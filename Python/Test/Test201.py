string = "hello world"
num = 666
f_num = 666.666
l = ['h','e','l','l','o',' ','w','o','r','l','d']

strsplit = string.split()  # 将隔着的字符串分开
print(strsplit)

strtitle = string.title()  # 将隔着的字符串首字母大写
print(strtitle)

strjoin =''.join(l)        # 将列表中的元素拼成字符串,前面是分隔符
print(strjoin)

l.append("!")              # 添加一个元素到数组末尾,可用下标来调整添加的位置
print(l)

x = l.pop(len(l)-1)        # 弹出一个指定下标元素,可以赋值给一个变量
print(x)       
print(l)

point = id(num)
print(point)               # 返回目标的地址

num = eval('2+3')          # 转换字符串成表达式并返回其值
print(num)

typeof = type(num)         # 返回数据的类型
print(typeof)

a = [1,2,3]
b = [4,5,6]
x = zip(a,b)               # 将迭代的目标压缩成一个数组
print(x)                   # 如[[1,2,3],[4,5,6]] 被压缩成 [(1,4),(2,5),(3,6)]