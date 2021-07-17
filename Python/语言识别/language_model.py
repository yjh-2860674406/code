import tensorflow as tf

from utils.constant import *
from utils.reLayers import *
# 组合语言模型
class language_model():
    def __init__(self, arg):
        self.graph = tf.Graph()
        with self.graph.as_default():
            self.is_training = arg.is_training # 是否训练
            self.hidden_units = arg.hidden_units # 隐藏神经元数量
            self.input_vocab_size = arg.input_vocab_size #输入长度
            self.label_vocab_size = arg.label_vocab_size # 标签长度
            self.num_heads = arg.num_heads #
            self.num_blocks = arg.num_blocks
            self.max_length = arg.max_length
            self.learning_rate = arg.learning_rate
            self.dropout_rate = arg.dropout_rate

            self.x = tf.placeholder(tf.int32, shape=(None, None))
            self.y = tf.placeholder(tf.int32, shape=(None, None))
            self.emb = embedding(self.x, vocab_size=self.input_vocab_size, num_units=self.hidden_units, scale=True, scope="enc_embed")
            self.enc = self.emb + embedding \
                (tf.tile(tf.expand_dims(tf.range(tf.shape(self.x)[1]), 0), [tf.shape(self.x)[0], 1]),
                                            vocab_size=self.max_length ,num_units=self.hidden_units, zero_pad=False, scale=False ,scope="enc_pe")
            self.enc = tf.layers.dropout(self.enc,
                                         rate=self.dropout_rate,
                                         training=tf.convert_to_tensor(self.is_training))

            for i in range(self.num_blocks):
                with tf.variable_scope("num_blocks_{}".format(i)):
                    self.enc = multihead_attention(emb = self.emb,
                                                   queries=self.enc,
                                                   keys=self.enc,
                                                   num_units=self.hidden_units,
                                                   num_heads=self.num_heads,
                                                   dropout_rate=self.dropout_rate,
                                                   is_training=self.is_training,
                                                   causality=False)

            self.outputs = feedforward(self.enc, num_units=[ 4 *self.hidden_units, self.hidden_units])

            self.logits = tf.layers.dense(self.outputs, self.label_vocab_size,name="output")
            self.preds = tf.to_int32(tf.argmax(self.logits, axis=-1))
            self.istarget = tf.to_float(tf.not_equal(self.y, 0))
            self.acc = tf.reduce_sum(tf.to_float(tf.equal(self.preds, self.y) ) *self.istarget )/ \
                (tf.reduce_sum(self.istarget))
            tf.summary.scalar('acc', self.acc) # 显示标量信息，精度

            if self.is_training:
                self.y_smoothed = label_smoothing(tf.one_hot(self.y, depth=self.label_vocab_size))
                self.loss = tf.nn.softmax_cross_entropy_with_logits_v2(logits=self.logits, labels=self.y_smoothed)
                self.mean_loss = tf.reduce_sum(self.loss * self.istarget) / (tf.reduce_sum(self.istarget))

                self.global_step = tf.Variable(0, name='global_step', trainable=False)
                self.optimizer = tf.train.AdamOptimizer(learning_rate=self.learning_rate, beta1=0.9, beta2=0.98,
                                                        epsilon=1e-8)
                self.train_op = self.optimizer.minimize(self.mean_loss, global_step=self.global_step)

                tf.summary.scalar('mean_loss', self.mean_loss)
                self.merged = tf.summary.merge_all()


print('语音模型建立完成！')