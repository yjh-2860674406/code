import numpy as np

a = np.array([[1,2,3], [4,5,6]])

b = np.array([[1,2], [3,4], [5,6]])

c = np.array([[1,2,3]])

d = np.array([[9,8,7], [3,2,1]])

# 矩阵加法
sum = a + d

# 放缩
e = 3 * a

# 矩阵乘法
e = np.dot(a, b)

# 转置
e = c.T

e = np.array([[1,2], [3,4]])

# 逆矩阵
result = np.linalg.inv(e)

# 行列式
result = np.linalg.det(e)

# 矩阵的秩
e = np.linalg.matrix_rank(d)