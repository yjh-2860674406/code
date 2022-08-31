import numpy as np
import pandas as pd

y = np.array([423, 358, 434, 445, 527, 429, 426, 502, 480, 384, 427, 446])

def ExpMove (y, a) :
    n = len(y)
    M = np.zeros(n)
    M[0] = y[0]
    for i in range(1, n) :
        M[i] = a * y[i-1] + (1-a) * M[i-1]
    return M

yt1 = ExpMove(y, 0.2)
yt2 = ExpMove(y, 0.5)
yt3 = ExpMove(y, 0.8)

s1 = np.sqrt(((y-yt1) ** 2).mean())
s2 = np.sqrt(((y-yt2) ** 2).mean())
s3 = np.sqrt(((y-yt3) ** 2).mean())

d = pd.DataFrame(np.c_[y, yt1, yt2, yt3])

print(d)