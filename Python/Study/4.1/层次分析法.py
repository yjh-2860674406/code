from traceback import print_tb
import numpy as np

A = np.array([[1, 1/3, 1/4, 1/5],
                    [3, 1, 3/4, 3/5],
                    [4, 4/3, 1, 4/5],
                    [5, 5/3, 5/4, 1]])
# 对比矩阵 A

n = len(A[0])
# A 的维度

RI = [0, 0, 0.58, 0.90, 1.12, 1.24, 1.32, 1.41, 1.45, 1.45, 1.49, 1.51]
# 

R = np.linalg.matrix_rank(A)
# A 的秩

V, D = np.linalg.eig(A)
# A 的特征值
# A 的特征向量

list1 = list(V)
# 列表化 V

B = np.max(list1)
# 最大 特征值

index = list1.index(B)
# 最大特征值的位置

C = D[:, index]
# 最大特征值对应的特征向量

CI = (B-n)/(n-1)
# 一致性检验的指标

CR = CI / RI[n]

if CR < 0.10 :
    print("CI : ", CI)
    print("CR : ", CR)
    print("对比矩阵A通过一致性检验, 各向量权重向量Q为：")
    sum = np.sum(C)

    Q = C/sum
    print(Q)
else :
    print("对比矩阵A未通过一致性检验，需对对比矩阵A重新构造")