import numpy as np

a1 = np.array([1,2,3,4])
a2 = np.array([5,6,7,8])
# print(a1+a2)
# print(a1-a2)
# print(a1*a2)
# print(a1/a2)

random_array = np.random.random((5,5))
# 0~1随机
rand1 = np.random.randint(100,size = (2,5))
# 0~100 随机
rand2 = np.random.randn(5,10)
# 正态分布 随机
# print(random_array)
# print(rand1)
# print(rand2)

eye_array = np.eye(4)
# 主对角线， 其余为0
# print(eye_array)

# print(np.isnan(random_array))
# 检测是否为nan
# print(np.sign(random_array))
# 检测每个元素的正负，正为1，负为-1
# print(np.nonzero(random_array))
# 返回非零元素的位置
# print(np.ceil(random_array))
# 拿到大于元素的最大整数
# print(np.cumsum(random_array))
# 计算数组的累计和
# print(np.diff(random_array))
# 计算数组的离散差值
# print(np.sort(random_array))
# 对数组进行排序

# print(random_array.T)
# 转置
# print(rand1.dot(rand2))
# 矩阵积
# inverse_random_array = np.linalg.inv(random_array)
# 逆矩阵
# print(np.linalg.det(random_array))
# 求行列式
# eigenvalues, eigenverctors = np.linalg.eig(random_array)
# 求特征值和特征向量

