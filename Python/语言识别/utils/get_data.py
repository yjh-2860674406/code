import numpy as np


from utils.constant import *
from utils.reLayers import *

import os

# file = os.path.join()


class get_data():
    def __init__(self, args): # 初始化参数
        self.data_path = args.data_path
        self.data_length = args.data_length # 训练数据长度
        self.batch_size = args.batch_size # batch大小
        self.source_init()

    def source_init(self):
        self.wav_lst = [] # 音频列表
        self.pin_lst = [] # 拼音列表
        self.han_lst = [] # 汉字列表
        # assert
        # data.txt 也在obs asr/data_thchs30里面
        # 如果我把路径都统一修改成这样，倒是可以找到上传到云端的文件，但是却没有办法在训练日志文件夹中保存模型
        with open('/cache/user-job-dir/code/data_thchs30/data.txt', 'r', encoding='GBK') as f:
        # 是不是我OBS的路径描述有问题？ 我看了官网给的例子，里面的文件夹路径用的不是这种相对路径
            data = f.readlines() # 将所有数据读入，分别将音频名称、对应拼音和汉字写入三个列表中
        for line in data: #
            wav_file, pin, han = line.split('\t') # 使用split切分音频、拼音、汉字
            self.wav_lst.append(wav_file) # 音频列表
            self.pin_lst.append(pin.split(' ')) # 拼音列表
            self.han_lst.append(han.strip('\n')) # 汉字列表
        if self.data_length:
            self.wav_lst = self.wav_lst[:self.data_length]
            self.pin_lst = self.pin_lst[:self.data_length]
            self.han_lst = self.han_lst[:self.data_length]
        self.acoustic_vocab = self.acoustic_model_vocab(self.pin_lst)
        self.pin_vocab = self.language_model_pin_vocab(self.pin_lst)
        self.han_vocab = self.language_model_han_vocab(self.han_lst)

    def get_acoustic_model_batch(self):
        _list = [i for i in range(len(self.wav_lst))]
        while 1:
            for i in range(len(self.wav_lst) // self.batch_size):
                wav_data_lst = []
                label_data_lst = []
                begin = i * self.batch_size
                end = begin + self.batch_size
                sub_list = _list[begin:end]
                for index in sub_list:
                    fbank = compute_fbank(self.data_path + self.wav_lst[index])
                    pad_fbank = np.zeros((fbank.shape[0] // 8 * 8 + 8, fbank.shape[1]))
                    pad_fbank[:fbank.shape[0], :] = fbank
                    label = self.pin2id(self.pin_lst[index], self.acoustic_vocab)
                    label_ctc_len = self.ctc_len(label)
                    if pad_fbank.shape[0] // 8 >= label_ctc_len:
                        wav_data_lst.append(pad_fbank)
                        label_data_lst.append(label)
                pad_wav_data, input_length = self.wav_padding(wav_data_lst)
                pad_label_data, label_length = self.label_padding(label_data_lst)
                inputs = {'the_inputs': pad_wav_data,
                          'the_labels': pad_label_data,
                          'input_length': input_length,
                          'label_length': label_length,
                          }
                outputs = {'ctc': np.zeros(pad_wav_data.shape[0], )}
                yield inputs, outputs

    def get_language_model_batch(self): # 生成batch
        batch_num = len(self.pin_lst) // self.batch_size
        for k in range(batch_num):
            begin = k * self.batch_size
            end = begin + self.batch_size
            input_batch = self.pin_lst[begin:end]
            label_batch = self.han_lst[begin:end]
            max_len = max([len(line) for line in input_batch])
            input_batch = np.array(
                [self.pin2id(line, self.pin_vocab) + [0] * (max_len - len(line)) for line in input_batch])
            label_batch = np.array(
                [self.han2id(line, self.han_vocab) + [0] * (max_len - len(line)) for line in label_batch])
            yield input_batch, label_batch

    def pin2id(self, line, vocab): # 根据索引将pinyin转化为数字
        return [vocab.index(pin) for pin in line]

    def han2id(self, line, vocab): # 根据索引将汉字转化为数字
        return [vocab.index(han) for han in line]

    def wav_padding(self, wav_data_lst):
        """
        语音序列填充
        :param wav_data_lst:
        :return:
        """
        wav_lens = [len(data) for data in wav_data_lst]
        wav_max_len = max(wav_lens)
        wav_lens = np.array([leng // 8 for leng in wav_lens])
        new_wav_data_lst = np.zeros((len(wav_data_lst), wav_max_len, 200, 1))
        for i in range(len(wav_data_lst)):
            new_wav_data_lst[i, :wav_data_lst[i].shape[0], :, 0] = wav_data_lst[i]
        return new_wav_data_lst, wav_lens

    def label_padding(self, label_data_lst):
        """
        填充标签序列，选择标签中最长的一句话，按照其长度对于其他标签进行补零的操作
        :param label_data_lst: 标签列表
        :return: 填充后的标签列表和长度
        """
        label_lens = np.array([len(label) for label in label_data_lst])
        max_label_len = max(label_lens)
        new_label_data_lst = np.zeros((len(label_data_lst), max_label_len))
        for i in range(len(label_data_lst)):
            new_label_data_lst[i][:len(label_data_lst[i])] = label_data_lst[i]
        return new_label_data_lst, label_lens

    def acoustic_model_vocab(self, data):
        vocab = []
        for line in data:
            line = line
            for pin in line:
                if pin not in vocab:
                    vocab.append(pin)
        vocab.append('_')
        return vocab

    def language_model_pin_vocab(self, data):
        vocab = ['<PAD>']
        for line in data:
            for pin in line:
                if pin not in vocab:
                    vocab.append(pin)
        return vocab

    def language_model_han_vocab(self, data):
        vocab = ['<PAD>']
        for line in data:
            line = ''.join(line.split(' '))
            for han in line:
                if han not in vocab:
                    vocab.append(han)
        return vocab

    def ctc_len(self, label):
        add_len = 0
        label_len = len(label)
        for i in range(label_len - 1):
            if label[i] == label[i + 1]:
                add_len += 1
        return label_len + add_len