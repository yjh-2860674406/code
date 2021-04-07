# while 初始化 && for 循环 && while continue break && if else && range() && 反向迭代 && input() 
l = []
y = '-'
x = int(input("请输入要排序的数组(输入-1结束):\n"))
# 初始化 x 并添加进数组
while True :
    l.append(x)
    x = int(input())
    if x == -1 :
        print(y*15)
        break
    else :
        continue

# 用嵌套 for 来进行 插入排序
for i in range(0,len(l)) :
    for j in range(i, 0, -1) :
        if l[j-1] > l[j] :
            temp = l[j]
            l[j] = l[j-1]
            l[j-1] = temp

# 用 for 循环来打印数组中的元素
for i in range(len(l)) :
    print(l[i])
print(y*15)