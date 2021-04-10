import tensorflow as tf

d = tf.random.normal([2, 2], mean=0.5, stddev=1)
# 生成正态分布的随机数，默认均值为0，标准差为1
print("d:", d)
e = tf.random.truncated_normal([2, 2], mean=0.5, stddev=1)
# 生成截断式正态分布的随机数，默认均值为0，标准差为1
print("e:", e)
