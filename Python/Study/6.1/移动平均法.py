from operator import le
import numpy as np

y = np.array([423, 358, 434, 445, 527, 429, 426, 502, 480, 384, 427, 446])

def MoveAverage (y, N) :
    Mt = [' ']*N
    for i in range(N+1, len(y)+2) :
        M = y[i-N-1 : i-1].mean()
        Mt.append(round(M))
    return Mt

yt3 = MoveAverage(y, 3)
yt5 = MoveAverage(y, 5)

s3 = np.sqrt(((y[3:] - yt3[3:-1]) ** 2).mean())
s5 = np.sqrt(((y[5:] - yt3[5:-1]) ** 2).mean())

print(yt3)

print(s3)

print(yt5)

print(s5)