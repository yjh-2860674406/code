# 导入工具包
from keras.layers import Input
from keras.layers import Reshape, Dense, Dropout, Lambda
from keras.optimizers import Adam
from keras.models import Model
from tensorflow.contrib.training import HParams
import warnings
warnings.filterwarnings("ignore")

# 导入自定义脚本
from utils.constant import *
from utils.reLayers import *

def acoustic_model_hparams(): # 设置模型参数
    params = HParams( # 使用 HParams 封装参数，类似于 content，只不过是以类的形式
        vocab_size = 50,
        learning_rate = Learning_RATE, # 学习率
        is_training = True)
    return params
#组合声学模型
class acoustic_model():
 """
 使用前面封装好的函数构建网络结构
 使用类的形式组合模型，如果要进一步封装可以将模型中的神经元数量写入 content
 """
def __init__(self, args): # args 为 acoustic_model_hparams 的返回值
     self.vocab_size = args.vocab_size # 获取当前词汇量
     self.learning_rate = args.learning_rate # 获取学习率
     self.is_training = args.is_training # 检测是需要训练
     self._model_init() #初始化模型
     if self.is_training:
         self._ctc_init() # 训练时在模型中加入算是函数和优化器
         self.opt_init()
def _model_init(self): # 模型初始化函数
    # 使用链式的结构创建模型
     self.inputs = Input(name='the_inputs', shape=(None, 200, 1)) # 创建输入层
     self.h1 = cnn_cell(32, self.inputs) # 使用封装好的函数创建第一个卷积层，卷积核 32
     self.h2 = cnn_cell(64, self.h1) # 使用封装好的函数创建第二个卷积层，卷积核 64
     self.h3 = cnn_cell(128, self.h2)
     self.h4 = cnn_cell(128, self.h3, pool=False)
     self.h5 = cnn_cell(128, self.h4, pool=False)
     # 200 / 8 * 128 = 3200
     self.h6 = Reshape((-1, 3200))(self.h5) # 对最后一个卷积层的输出做维度变换，然后作为全连接层的输入
     self.h6 = Dropout(0.2)(self.h6) #
     self.h7 = dense(256)(self.h6) # 全连接层，神经元数量 256
     self.h7 = Dropout(0.2)(self.h7)
     self.outputs = dense(self.vocab_size, activation='softmax')(self.h7)
     self.model = Model(inputs=self.inputs, outputs=self.outputs)
def _ctc_init(self): # 初始化 CTC 损失函数
     self.labels = Input(name='the_labels', shape=[None], dtype='float32')
     self.input_length = Input(name='input_length', shape=[1], dtype='int64')
     self.label_length = Input(name='label_length', shape=[1], dtype='int64')
     self.loss_out = Lambda(ctc_lambda, output_shape=(1,), name='ctc')\
     ([self.labels, self.outputs, self.input_length, self.label_length])# 使用 Lambda 函数“包装”CTC
     self.ctc_model = Model(inputs=[self.labels, self.inputs, # 将损失函数添加至模型中
         self.input_length, self.label_length], outputs=self.loss_out)
def opt_init(self): # 创建优化器
     opt = Adam(lr = self.learning_rate, beta_1 = 0.9, beta_2 = 0.999, decay = 0.01, epsilon = 10e-8)
    # 创建优化器，设置学习率和衰减系数等参数
     self.ctc_model.compile(loss={'ctc': lambda y_true, output: output}, optimizer=opt) # 添加 adam
if __name__ == "__main__": # 用与当前脚本的测试，在导入该脚本后不会运行此段代码
     print("打印声学模型结构")
     acoustic_model_args = acoustic_model_hparams()
     acoustic = acoustic_model(acoustic_model_args)
acoustic.ctc_model.summary()