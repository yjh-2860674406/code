#include <stdio.h>

void swap (int a, int b)
{
    a += b;
    b = a - b;
    a -= b;
    printf("��ӡ������a �� b �ĵ�ַ��\n");
    printf("%p, %p\n", &a, &b);
}

int main()
{
    int a=1, b=2;
    printf("��ӡa �� b �ĵ�ַ��\n");
    printf("%p, %p\n", &a, &b);
    swap(a, b);
}