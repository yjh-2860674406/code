#include <stdio.h>

void swap(int a, int b)
{
    a += b;
    b = a-b;
    a -= b;
    printf("函数内：\n");
    printf("%d, %d\n", a, b);
}

void swapp(int *p1, int *p2)
{
    *p1 += *p2;
    *p2 = *p1 - *p2;
    *p1 -= *p2;
    printf("函数内：\n");
    printf("%d, %d\n", *p1, *p2);
}

int main()
{
    int a = 3, b = 4;
    printf("\n");
    printf("------------普通变量作为形参------------\n");
    swap (a,b);
    printf("函数外：\n");
    printf("%d, %d\n", a, b);
    printf("\n并未改变a， b的值，只是改变了函数内局部变量的值。\n");
    printf("\n");
    printf("------------指针变量作为形参------------\n");
    swapp (&a, &b);
    printf("函数外：\n");
    printf("%d, %d\n", a, b);
    printf("\n改变了a， b在内存中的值，通过指针修改。\n");
    return 0;
}