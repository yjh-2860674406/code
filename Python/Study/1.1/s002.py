import numpy as np

A = np.array([[10, -1, -2], [-1, 10, -2], [-1, -1, 5]])

b = np.array([[72], [83], [42]])

# inv_A = np.linalg.inv(A)
# x = inv_A.dot(b)
# [[x], [y], [z]] = A.inv * b

x = np.linalg.solve(A, b)

print(x)

# 10x - y - 2z = 72
# -x + 10y - 2z = 83
# -x -y + 5z = 42