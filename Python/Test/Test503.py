# 列表嵌套 && 集合 && 字典(嵌套进列表)
# append() && del() && pop()
# .keys() && .values() && .items()
l = []
a = [1,2,3]
b = [4,5,6]
c = [7,8,9]
l.append(a)
# append() 向列表中添加元素
l.append(b)
l.append(c)
# 列表嵌套
# print(l[2][2])

set = {1,1,2,3}
# 集合
# print(set) 

x = []
color = {1:"red", 2:"yellow", 3:"orange"}
fruit = {1:"apple", 2:"banana", 3:"orange"}
price = {1:12.25, 2:7.5, 3:21.25}
# 字典
x.append(color)
x.append(fruit)
x.append(price)
# for i in range(1,4) :
    # print("%s的颜色:%s\n%s的价格%.2f:"%(x[1][i], x[0][i], x[1][i], x[2][i]))
# 打印水果的颜色价格

y = []
y.append(1)
y.append(2)
y.append(3)
y.append(4)
# print(y)
# y = [1, 2, 3, 4]
del y[3]
# 删除指定下标的元素(可指定范围)
# print(y)
# y = [1, 2, 3]
y.append(4)
# y = [1, 2, 3, 4]
m = y.pop(3)
# 弹出指定下标的元素
# 可以用这个元素给变量赋值
# print(y)
# y = [1, 2, 3]
# print(m)
# m = 4

dic = {"yjh":"student", "cy":"student"}
# print("cy is a", dic["cy"])
# print(dic.keys())
# dict_keys(['yjh', 'cy'])
# 打印出字典中所有的关键字
# print(dic.values())
# dict_values(['student', 'student'])
# 打印出字典中所有的值
# print(dic.items())
# dict_items([('yjh', 'student'), ('cy', 'student')])
# 打印出字典所有关键字和其对应的值


