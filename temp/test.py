list = ['1','2','3','4']

# 在列表末尾添加元素
list.append('5')

# 在特定位置添加元素
list.insert(0, '0')

# 删除特定位置的元素
del list[5]

# 弹出并可以使用末尾元素，括号内可指定位置
print(list.pop())

# 删除指定值(第一个)
list.remove('0')

# 对列表进行字母顺序的永久排序(reversed=True 相反)
list.sort()
list.sort(reversed=True)

# 临时排序
sorted(list)
sorted(list, reverse=True)

# 数组的长度
len(list)
