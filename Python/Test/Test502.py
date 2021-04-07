# enumerate && if elif else
week = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

def check() :
    i = int(input("请输入你要查询的日期(数字):\n"))
    if i>0 and i<6 :
        print("今天是%s, 是工作日!"%week[i-1])
    elif i>5 and i<8 :
        print("今天是%s, 是休息日!"%week[i-1])
    else :
        print("输入错误,请重新输入!")
        check()

for i,e in enumerate(week) :
    print(i+1, e)

check()
