#include <stdio.h>

int Max(int a, int b, int c);

int main()
{
    int a,b,c,d;
    printf("�������������� :\n");
    scanf("%d, %d, %d", &a, &b, &c);
    d = Max(a,b,c);
    printf("��������: %d", d);
    return 0;
}

int Max(int a, int b, int c)
{
    if (a > b) 
        {if (a > c)
            return a;
        }
    else 
        {if (b > c)
            return b;
        else 
            return c;
        }
}