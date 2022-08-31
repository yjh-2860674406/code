from random import random
import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]

height = [random()*10 for i in range(5)]

plt.bar(x, height)
# x
# height 
# width
# align

plt.show()