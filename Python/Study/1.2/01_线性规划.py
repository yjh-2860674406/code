# 规范式

# 目标函数
# min c.T * x 

# 约束条件
# A * x <= b
# Aeq * x = beq
# lb <= x <= ub

# 求
# max z = 2x1 + 3x2 - 5x3

# x1 + x2 + x3 = 7
# 2x1 -5x2 + x3 >= 10
# x1 + 3x2 + x3 <= 12
# x1, x2, x3 >= 0

from scipy.optimize import linprog
import numpy as np

c = np.array([-2,-3,5])

A = np.array([[-2, 5, -1], [1, 3, 1]])

b = np.array([[-10, 12]])

Aeq = np.array([[1,1,1]])

beq = np.array([7])

x1 = (0, None)
x2 = (0, None)
x3 = (0, None)

res = linprog(c, A, b, Aeq, beq, bounds=(x1, x2, x3))

print(res)