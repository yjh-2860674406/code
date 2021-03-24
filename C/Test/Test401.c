#include <stdio.h>

int main()
{
    int mark = 0;
    printf("请输入您的分数:\n");
    scanf("%d", &mark);
    if (mark >= 90)
    {
        printf("A");
    }
    else if (mark >= 80)
    {
        printf("B");
    }
    else if (mark >= 70)
    {
        printf("C");
    }
    else if (mark >= 60)
    {
        printf("D");
    }
    else
    {
        printf("E");
    }
    return 0;
}