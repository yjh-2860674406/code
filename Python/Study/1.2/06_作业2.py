import numpy as np
from scipy.optimize import minimize
from sko.GA import GA

def fun (x) :
    return x[0]**2 + 3*(x[1]**2) - x[0]*x[2]

cons1 = ({'type' : 'eq', 'fun' : lambda x : x[0] + x[1] + x[2] - 70})
cons2 = ({'type' : 'ineq', 'fun' : lambda x : 100 - x[0] - x[1] - 3*x[2]})
cons3 = ({'type' : 'ineq', 'fun' : lambda x : -2*x[1] + x[2] - 15})
cons4 = ({'type' : 'ineq', 'fun' : lambda x : 400 - x[0]**2 - x[1]**2})

cons = (cons1, cons2, cons3, cons4)

x1 = x2 = x3 = (0.0, None)

x0 = np.array([20, 5, 25])

res = minimize(fun, x0, method="SLSQP", bounds=(x1, x2, x3), constraints=cons)

print(res)


# cons1 = lambda x : 70 - x[0] - x[1] - x[2]
# cons2 = lambda x : -100 + x[0] + x[1] + 3*x[2]
# cons3 = lambda x : 2*x[1] - x[2] + 15
# cons4 = lambda x : -400 + x[0]**2 - x[1]**2

# conseq = [cons1]
# consineq = [cons2, cons3, cons4]

# ga = GA(func=fun, n_dim=3, size_pop=500, max_iter=1000, constraint_eq=conseq, constraint_ueq=consineq, lb = [0, 0, 0], ub = [40, 40, 40], prob_mut = 0.01)

# best_x, best_y = ga.run()

# print(best_x, best_y)
