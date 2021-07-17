from tensorflow.contrib.training import HParams
import os
import moxing as mox

mox.file.shift('os', 'mox')
import shutil

from language_model import language_model
from train_AcousticModel import train_data, batch_num
from utils.constant import *
from utils.get_data import *


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
        is_training = True)
    return params
if __name__ == "__main__":
    language_model_args = language_model_hparams()
    language_model_args.input_vocab_size = len(train_data.pin_vocab)
    language_model_args.label_vocab_size = len(train_data.han_vocab)
    language = language_model(language_model_args)

    print('语言模型参数：')
    print(language_model_args)

    epochs = 2
    print("训练轮数epochs：",epochs)
    # batch = train_data.get_acoustic_model_batch()
    print("\n开始训练！")
    with language.graph.as_default():
        saver =tf.train.Saver()
    with tf.Session(graph=language.graph) as sess:

        merged = tf.summary.merge_all()
        sess.run(tf.global_variables_initializer())
        print(tf.global_variables())
        if os.path.exists('obs://13692313203/Video'):
            shutil.copytree("obs://13692313203/Video", )
            print('加载语言模型')
            saver.restore(sess, './model_language/model_language/')
        writer = tf.summary.FileWriter('/cache/user-job-dir/code/data_thchs30/tensorboard', tf.get_default_graph())
        for k in range(epochs):
            total_loss = 0
            batch = train_data.get_language_model_batch()
            for i in range(batch_num):
                input_batch, label_batch = next(batch)
                feed = {language.x: input_batch, language.y: label_batch}
                cost,_ = sess.run([language.mean_loss,language.train_op], feed_dict=feed)
                total_loss += cost
                if (k * batch_num + i) % 10 == 0:
                    rs=sess.run(merged, feed_dict=feed)
                    # writer.add_summary(rs, k * batch_num + i)
            print('第', k+1, '个 epoch', ': average loss = ', total_loss/batch_num)
        print("\n训练完成，保存模型")
        saver.save(sess, '/cache/user-job-dir/code/data_thchs30/model_language/model_language')
        writer.close()

        shutil.copytree("/cache/user-job-dir/code/data_thchs30/model_language/","obs:///guidian23/asr/model_language/")