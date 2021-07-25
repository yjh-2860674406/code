#include <stdio.h>

int stack_prn[100];
int X;

void Empty ()
{
    X = 0;
}

void push (int num)
{
    stack_prn[X] = num;
    X++;
}

int pop ()
{
    int temp = stack_prn[X-1];
    X--;
    return temp;
}

int Prn ()
{
    char temp;
    scanf("%c",&temp);
    // 获取字符串
    int num = (int)temp-48;
    // 将字符串转换成数字
    while (temp != (int)'=')
    // 遇到‘=’结束循环
    {
        getchar();
        // 吃掉一个字符
        switch (temp)
        // switch语句判断是否为运算符
        {
            case ('+') :
            {
                int x = pop();
                int y = pop();
                push(y+x);
            }
            break;
            case ('-') :
            {
                int x = pop();
                int y = pop();
                push(y-x);
            }
            break;
            case ('*') :
            {
                int x = pop();
                int y = pop();
                push(y*x);
            }
            break;
            case ('/') :
            {
                int x = pop();
                int y = pop();
                push(y/x);
            }
            break;
            default :
            // 不是运算符则将数压入栈
            push(num);
        }
        // 重复
        scanf("%c", &temp);
        num = (int)temp-48;
    }
    // 返回栈顶
    return pop();
}

int main()
{
    int x = Prn();
    printf("%d\n", x);
    return 0;
}