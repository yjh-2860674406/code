
import os
from tensorflow.contrib.training import HParams

import os
import moxing as mox

mox.file.shift('os', 'mox')
import shutil


import sys
import os
sys.path.append(os.getcwd())
from utils.get_data import *
from AcousticModel import *
from utils.constant import *

def data_hparams():
    params = HParams(
        data_path = '/cache/user-job-dir/code/data_thchs30/data/', # 数据路径，本地训练要更换本地路径
        batch_size = Batch_SIZE,      #批尺寸
        data_length = None,   #设置训练数据集长度，可用于教学查看效果
    )
    return params


import os
data_args = data_hparams()
# data_args.data_length = 20 # 重新训练需要注释该行
train_data = get_data(data_args)

acoustic_model_args = acoustic_model_hparams()
acoustic_model_args.vocab_size = len(train_data.acoustic_vocab)
acoustic = acoustic_model(acoustic_model_args)

print('声学模型参数：')
print(acoustic_model_args)

if os.path.exists('obs://13692313203/Video'): # 检测OBS中当前模型是否存在，obsname：桶名称
    shutil.copyfile("obs://13692313203/Video",)
    print('加载声学模型')
    acoustic.ctc_model.load_weights('./model.h5')
epochs = EPOCHS
batch_num = len(train_data.wav_lst) // train_data.batch_size
if __name__ == "__main__":

    print("训练轮数epochs：",epochs)
    print("批数量batch_num：",batch_num)

    print("开始训练！")
    for k in range(epochs):
        print('第', k+1, '个epoch')
        batch = train_data.get_acoustic_model_batch()
        acoustic.ctc_model.fit_generator(batch, steps_per_epoch=batch_num, epochs=1)

    print("\n训练完成，保存模型")
    acoustic.ctc_model.save_weights('/cache/user-job-dir/code/data_thchs30/model.h5')
    shutil.copyfile("/cache/user-job-dir/code/data_thchs30/model.h5","obs:///guidian23/asr/AcousticModel/model.h5")
