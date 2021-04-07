# 列表嵌套 && 集合 && 字典(嵌套进列表) && 
l = []
a = [1,2,3]
b = [4,5,6]
c = [7,8,9]
l.append(a)
l.append(b)
l.append(c)
# print(l[2][2])

set = {1,1,2,3}
# print(set) 

x = []
color = {1:"red", 2:"yellow", 3:"orange"}
fruit = {1:"apple", 2:"banana", 3:"orange"}
price = {1:12.25, 2:7.5, 3:21.25}
x.append(color)
x.append(fruit)
x.append(price)
# for i in range(1,4) :
    # print("%s的颜色:%s\n%s的价格%.2f:"%(x[1][i], x[0][i], x[1][i], x[2][i]))

