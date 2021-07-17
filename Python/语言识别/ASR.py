import shutil
import moxing as mox
mox.file.shift('os', 'mox')


from language_model import language_model
from train_AcousticModel import data_hparams, acoustic_model_hparams, acoustic_model
from train_language_model import language_model_hparams
from utils.get_data import *


data_args = data_hparams()
# data_args.data_length = 20 # 重新训练需要注释该行
train_data = get_data(data_args)


test_data = get_data(data_args)
acoustic_model_batch = test_data.get_acoustic_model_batch()
language_model_batch = test_data.get_language_model_batch()

acoustic_model_args = acoustic_model_hparams()
acoustic_model_args.vocab_size = len(train_data.acoustic_vocab)
acoustic = acoustic_model(acoustic_model_args)
# acoustic.ctc_model.summary()

shutil.copyfile("obs:///guidian23/asr/AcousticModel/model.h5","./model.h5",)
acoustic.ctc_model.load_weights('./model.h5')

print('声学模型参数：')
print(acoustic_model_args)
print('\n加载声学模型完成！')

language_model_args = language_model_hparams()
language_model_args.input_vocab_size = len(train_data.pin_vocab)
language_model_args.label_vocab_size = len(train_data.han_vocab)
language = language_model(language_model_args)
sess = tf.Session(graph=language.graph)
with language.graph.as_default():
    saver =tf.train.Saver()
with sess.as_default():
    shutil.copytree("obs://guidian23/asr/model_language/", "./model_language/", )
    print('加载语言模型')
    saver.restore(sess, './model_language/model_language')


print('语言模型参数：')
print(language_model_args)
print('\n加载语言模型完成！')

def decode_ctc(num_result, num2word):
    result = num_result[:, :, :]
    in_len = np.zeros((1), dtype = np.int32)
    in_len[0] = result.shape[1]
    t = K.ctc_decode(result, in_len, greedy = True, beam_width=10, top_paths=1)
    v = K.get_value(t[0][0])
    v = v[0]
    text = []
    for i in v:
        text.append(num2word[i])
    return v, text
# 模型测试

for i in range(10):
    print('\n示例', i + 1)
    # 载入训练好的模型，并进行识别
    inputs, outputs = next(acoustic_model_batch)
    x = inputs['the_inputs']
    y = inputs['the_labels'][0]
    result = acoustic.model.predict(x, steps=1)
    # 将数字结果转化为文本结果
    _, text = decode_ctc(result, train_data.acoustic_vocab)
    text = ' '.join(text)
    print('原文拼音：', ' '.join([train_data.acoustic_vocab[int(i)] for i in y]))
    print('识别结果：', text)
    # with sess.as_default():
    #     try:
    #         _, y = next(language_model_batch)
    #
    #         text = text.strip('\n').split(' ')
    #         x = np.array([train_data.pin_vocab.index(pin) for pin in text])
    #         x = x.reshape(1, -1)
    #         preds = sess.run(language.preds, {language.x: x})
    #         got = ''.join(train_data.han_vocab[idx] for idx in preds[0])
    #         print('原文汉字：', ''.join(train_data.han_vocab[idx] for idx in y[0]))
    #         print('识别结果：', got)
    #     except StopIteration:
    #         break
sess.close()
