#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i;
    int sum;
    char ch;
    printf("������һ��������������Ŀ�Ŀո�:");

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
    printf("�����:%d", sum);
    printf("\n");
    system("pause");
}