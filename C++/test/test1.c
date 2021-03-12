#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i;
    int sum;
    char ch;
    printf("请输入一串整数和任意数目的空格:");

    while (scanf("%d", &i) == 1)
    {
        sum += i;

        while ((ch=getchar()) == ' ')
            ;
        {
            if (ch == '\n')
            {
                break;
            }
            
            ungetc(ch, stdin);
        }
        
    }
    printf("结果是:%d", sum);
    printf("\n");
    system("pause");
}