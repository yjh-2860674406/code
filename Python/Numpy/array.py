import numpy as np

np_array = np.array([1,2,3])
# print(type(np_array))
# print(np_array)

zero_array = np.zeros((4,5))
one_array = np.ones((5))
full_array = np.full((3,5), 7)
empty_array = np.empty((2,3))
# print(zero_array)
# print(one_array)
# print(full_array)
# print(empty_array)

# print(zero_array.shape)
# print(zero_array.ndim)
# 打印出维度
# print(zero_array.size)
# 打印出元素个数
# print(zero_array.dtype)
# 打印出元素数据类型
# print(zero_array.itemsize)
# 打印出元素的内存空间大小

x = zero_array.copy()
# 复制
x.shape = (2,10)
# print(x)
# 改变现状


