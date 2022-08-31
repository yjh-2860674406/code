import numpy as np

def getW (M) :
    P = M / M.sum(axis = 0)
    E = np.nansum( -P * np.log(P) / np.log(len(M)), axis=0)
    return (1-E) / (1-E).sum()

M = np.array([[1, 2, 3, 4], 
                    [2, 1, 4, 2],
                    [3, 2, 3, 4]])

print(getW(M))