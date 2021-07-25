#include <stdio.h>

void swap (int a, int b)
{
    a += b;
    b = a - b;
    a -= b;
    printf("打印函数内a 和 b 的地址：\n");
    printf("%p, %p\n", &a, &b);
}

int main()
{
    int a=1, b=2;
    printf("打印a 和 b 的地址：\n");
    printf("%p, %p\n", &a, &b);
    swap(a, b);
}