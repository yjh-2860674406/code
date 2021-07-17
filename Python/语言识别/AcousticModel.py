
from keras.layers import Input
from keras.layers import Reshape, Dense, Dropout, Lambda
from keras.optimizers import Adam
from keras.models import Model
from tensorflow.contrib.training import HParams
import warnings
warnings.filterwarnings("ignore")


from utils.constant import *
from utils.reLayers import *

def acoustic_model_hparams():
    params = HParams(
        vocab_size = 50,
        learning_rate = Learning_RATE,
        is_training = True)
    return params



class acoustic_model():

    def __init__(self, args):
        self.vocab_size = args.vocab_size
        self.learning_rate = args.learning_rate
        self.is_training = args.is_training
        self._model_init()
        if self.is_training:
            self._ctc_init()
            self.opt_init()

    def _model_init(self):
        self.inputs = Input(name='the_inputs', shape=(None, 200, 1))
        self.h1 = cnn_cell(32, self.inputs)
        self.h2 = cnn_cell(64, self.h1)
        self.h3 = cnn_cell(128, self.h2)
        self.h4 = cnn_cell(128, self.h3, pool=False)
        self.h5 = cnn_cell(128, self.h4, pool=False)
        # 200 / 8 * 128 = 3200
        self.h6 = Reshape((-1, 3200))(self.h5)
        self.h6 = Dropout(0.2)(self.h6)
        self.h7 = dense(256)(self.h6)
        self.h7 = Dropout(0.2)(self.h7)
        self.outputs = dense(self.vocab_size, activation='softmax')(self.h7)
        self.model = Model(inputs=self.inputs, outputs=self.outputs)

    def _ctc_init(self):
        self.labels = Input(name='the_labels', shape=[None], dtype='float32')
        self.input_length = Input(name='input_length', shape=[1], dtype='int64')
        self.label_length = Input(name='label_length', shape=[1], dtype='int64')
        self.loss_out = Lambda(ctc_lambda, output_shape=(1,), name='ctc')\
            ([self.labels, self.outputs, self.input_length, self.label_length])
        self.ctc_model = Model(inputs=[self.labels, self.inputs,
            self.input_length, self.label_length], outputs=self.loss_out)

    def opt_init(self):
        opt = Adam(lr = self.learning_rate, beta_1 = 0.9, beta_2 = 0.999, decay = 0.01, epsilon = 10e-8)
        self.ctc_model.compile(loss={'ctc': lambda y_true, output: output}, optimizer=opt)


if __name__ == "__main__":
    print("print the model structure of acoustic model.")
    acoustic_model_args = acoustic_model_hparams()
    acoustic = acoustic_model(acoustic_model_args)
    acoustic.ctc_model.summary()