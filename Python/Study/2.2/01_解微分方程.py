from cProfile import label
from unittest import result
import sympy as sy
import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

# def eq (x, f) :
#     return sy.diff(f(x), x, 2) + 4 * sy.diff(f(x), x, 1) + 29 * f(x)

# x = sy.symbols('x')
# f = sy.Function('f')

# print(sy.dsolve(eq(x, f)), f(x))


# def eq (y, x) :
#     return np.array(y)

# x = np.linspace(0, 1, num=100)

# result = odeint(eq, 1, x)

# plt.plot(x, result[ : , 0])
# plt.grid()
# plt.show()

def eq (y_list, x) :
    y, z = y_list
    return np.array([z, -y])

x = np.linspace(0, np.pi*2, num=100)

y0 = [1, 1]

result = odeint(eq, y0, x)

plt.plot(x, result[ : , 0], label = 'y')
plt.plot(x, result[ : , 1], label = 'z')

plt.legend()
plt.grid()
plt.show()

