from random import random
from turtle import color
import matplotlib.pyplot as plt


x = range(1, 15, 1)

y1 = []
for i in range(1, 15) :
    y1.append(random() * 10)

y2 = []
for i in range(1, 15) :
    y2.append(random() * 10)

plt.figure(facecolor="yellow", figsize=(10, 5))
# facecolor : 画布颜色
# figsize : 画布大小

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.xlabel("x轴")
plt.ylabel("y轴")
# x, y轴的标题

plt.plot(x, y1, color='b', linestyle='-.', marker='o')
plt.plot(x, y2, color='r', linestyle='--', marker='*')
# [x], [y]
# color : 线的颜色
#           "r" : "red"
#           "y" : "yello"
#           "b" : "blue"
#           "g" : "green"
# linestyle : 线的样式
#           "-" : "实线"
#           "--" : "双线"
#           "-." : "点划线"
#           ":" : "虚线"
# marker : 点的样式
#           "." : "点"
#           "," : "像素"
#           "o" : "实心圆"
#           "v" : "倒三角"
#           "^" : "上三角"
#           "<" : "左三角"
#           ">" : "右三角"
#           "1" : "下花三角"
#           "2" : "上花三角"
#           "3" : "左花三角"
#           "4" : "右花三角"
#           "s" : "实心正方形"
#           "p" : "实心五角形"
#           "*" : "星形"

plt.yticks(range(0, 10))
plt.xticks(range(1, 15))
# x, y 轴的刻度

plt.grid()
# 网格线

plt.legend(["test1", "test2"])

plt.show()