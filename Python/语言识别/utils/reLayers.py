# 导入 Python 工具库
import tensorflow as tf
from keras.layers import Conv2D, BatchNormalization, MaxPooling2D
from keras.layers import Dense
from keras import backend as K
import numpy as np
import scipy.io.wavfile as wav
from scipy.fftpack import fft
import warnings
warnings.filterwarnings("ignore") # 用于忽略警告信息
# 导入自定义工具文件
from utils.constant import *
#定义卷积层
def conv2d(size):
    return Conv2D(size, Conv2D_SIZE, use_bias=True, activation='relu',padding='same', kernel_initializer='he_normal') # 设置卷积核尺寸、填充和激活函数
#定义 BN 层
def norm(x):
    return BatchNormalization(axis=-1)(x)
#定义最大池化层
def maxpool(x):
    return MaxPooling2D(pool_size=Pool_SIZE, strides=None, padding="valid")(x)
#定义 dense 层
def dense(units, activation="relu"):
    return Dense(units, activation=activation, use_bias=True,kernel_initializer='he_normal')
#两个卷积层加一个最大池化层的组合
def cnn_cell(size, x, pool=True):
    x = norm(conv2d(size)(x))
    x = norm(conv2d(size)(x))
    if pool:
        x = maxpool(x)
        return x
#CTC 损失函数
def ctc_lambda(args):
    labels, y_pred, input_length, label_length = args
    y_pred = y_pred[:, :, :]
    return K.ctc_batch_cost(labels, y_pred, input_length, label_length)
# 获取语谱图函数
def compute_fbank(file):
    x=np.linspace(0, 400 - 1, 400, dtype = np.int64)
    w = 0.54 - 0.46 * np.cos(2 * np.pi * (x) / (400 - 1) ) # 汉明窗
    fs, wavsignal = wav.read(file)
    # wav 波形 加时间窗以及时移 10ms
    time_window = 25 # 单位 ms
    window_length = fs / 1000 * time_window # 计算窗长度
    wav_arr = np.array(wavsignal)
    wav_length = len(wavsignal)
    range0_end = int(len(wavsignal)/fs*1000 - time_window) // 10
    data_input = np.zeros((range0_end, 200), dtype = np.float) # 用于存放最终的频率特征数据
    data_line = np.zeros((1, 400), dtype = np.float)
    for i in range(0, range0_end):
        p_start = i * 160
        p_end = p_start + 400
        data_line = wav_arr[p_start:p_end]
        data_line = data_line * w # 加窗
        data_line = np.abs(fft(data_line))
        data_input[i]=data_line[0:200] # 设置为 400 除以 2 的值（即 200）是取一半数据，因为是对称的
        data_input = np.log(data_input + 1)
        return data_input