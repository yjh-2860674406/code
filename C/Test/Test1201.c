#include <stdio.h>

void swap(int a, int b)
{
    a += b;
    b = a-b;
    a -= b;
    printf("�����ڣ�\n");
    printf("%d, %d\n", a, b);
}

void swapp(int *p1, int *p2)
{
    *p1 += *p2;
    *p2 = *p1 - *p2;
    *p1 -= *p2;
    printf("�����ڣ�\n");
    printf("%d, %d\n", *p1, *p2);
}

int main()
{
    int a = 3, b = 4;
    printf("\n");
    printf("------------��ͨ������Ϊ�β�------------\n");
    swap (a,b);
    printf("�����⣺\n");
    printf("%d, %d\n", a, b);
    printf("\n��δ�ı�a�� b��ֵ��ֻ�Ǹı��˺����ھֲ�������ֵ��\n");
    printf("\n");
    printf("------------ָ�������Ϊ�β�------------\n");
    swapp (&a, &b);
    printf("�����⣺\n");
    printf("%d, %d\n", a, b);
    printf("\n�ı���a�� b���ڴ��е�ֵ��ͨ��ָ���޸ġ�\n");
    return 0;
}