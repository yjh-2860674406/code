import tensorflow as tf

f = tf.random.uniform([2, 2], minval=0, maxval=1)
# 在最小最大之间生成均匀分布随机数 前闭后开
print("f:", f)
