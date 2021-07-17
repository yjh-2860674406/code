
from tensorflow.contrib.training import HParams
import os

from language_model import language_model
from train_AcousticModel import train_data, batch_num
from utils.constant import *
from utils.get_data import *


ckpt_path = './model_language/model_language'


output_graph = './model_language/frozen_model.pb'
def language_model_hparams():
    params = HParams(
        num_heads = 8,
        num_blocks = 6,
        input_vocab_size = 50,
        label_vocab_size = 50,
        max_length = 100,
        hidden_units = 512,
        dropout_rate = Dropout_RATE,
        learning_rate = Learning_RATE,
        is_training = False)
    return params

language_model_args = language_model_hparams()
language_model_args.input_vocab_size = len(train_data.pin_vocab)
language_model_args.label_vocab_size = len(train_data.han_vocab)
language = language_model(language_model_args)


# with tf.Session(graph=language.graph) as sess:

    # for i in tf.global_variables():
    #     print(i)

output_node_name = ["output"]

with language.graph.as_default():
    saver =tf.train.Saver()
with tf.Session(graph=language.graph) as sess:

    sess.run(tf.global_variables_initializer())
    saver = tf.train.Saver(var_list=tf.global_variables())
    saver.restore(sess, ckpt_path)
    # print(tf.global_variables())

    graph = tf.get_default_graph()
    input_graph_def = graph.as_graph_def()
    output_graph_def = tf.graph_util.convert_variables_to_constants(
        sess,
        input_graph_def,
        output_node_name
    )

    with tf.gfile.GFile(output_graph, "wb") as f:
        f.write(output_graph_def.SerializeToString())


# freeze_graph()

