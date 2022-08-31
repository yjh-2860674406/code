from scipy.optimize import linprog
import numpy as np

Aeq = np.array([[1, 1, 1]])

beq = np.array([70])

A = np.array([[1, 1, 1],
                    [0, 2, -1],
                    [-3, 1, 4]])

b = np.array([100, -15, -40])

c = np.array([2, 3, -1])

x1 = x2 = x3 = (0, None)

res = linprog(c, A, b, Aeq, beq, bounds=(x1, x2, x3))

print(res.x)