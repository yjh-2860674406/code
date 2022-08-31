from sko.GA import GA

def fun (x) :
    return 10.5 + 0.3*x[0] + 0.32*x[1] + 0.32*x[2] + 0.0007*x[0]**2 + 0.0004*x[1]**2 + 0.00045*x[2]**2

def func(x) :
    return x[0] + x[1] + x[2] - 700

# cons = [{'type' : 'eq' , 'func' : lambda x : x[0] + x[1] + x[2] == 700}]

ga = GA(func=fun, n_dim=3, size_pop=500, max_iter=1000, constraint_eq= [lambda x : func(x)], lb = [100, 120, 150], ub = [200, 250, 300])

best_x, best_y = ga.run()

print("best_x = ", best_x, " best_y = ", best_y)