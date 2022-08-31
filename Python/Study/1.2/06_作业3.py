from scipy.optimize import linear_sum_assignment
import numpy as np

cost = np.array([[22, 16, 20, 35, 18], 
                        [20, 12, 35, 40, 26], 
                        [11, 19, 15, 17, 21],
                        [25, 30, 21, 37, 40],
                        [22, 26, 35, 30, 19]])

row_ind, col_ind = linear_sum_assignment(cost)

print(row_ind)
print(col_ind)

print(cost[row_ind, col_ind])
print(cost[row_ind, col_ind].sum())