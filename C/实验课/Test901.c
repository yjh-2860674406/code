#include <stdio.h>
#include <stdbool.h>
#define STACKSIZE 200

int Mystack[STACKSIZE];
int X=0;

void make_empty(void)
{
    X = 0;
}

bool is_empty (void)
{   
    if (X == 0) return true;
    else return false;
}

bool is_full (void)
{
    if (X == 200) return true;
    else return false;
}

void stack_push (int t)
{
    Mystack[X] = t;
    X++;
}

int stack_pop (void)
{
    if (X == 0) 
    {
        printf("��ջ��\n");
        return 0;
    }
    else 
    {
        int temp = Mystack[X-1];
        X--;
        return temp;
    }
}

int main()
{
    make_empty(); 
    // ��ն�ջ //

    if (is_empty() == true) printf("��ջ\n");
    else printf("����\n");
    // �ж��Ƿ������ //

    for (int i=0; i<201; i++) stack_push(i);
    int pop = stack_pop();
    // ��0��199 ����ջ //

    if (is_full() == true) printf("��ջ\n");
    else printf("û��\n");
    // �ж���û���� //

    for (int i=0; i<STACKSIZE; i++)
    {
        printf("%d\t", stack_pop());
        if ((i+1)%5 == 0) printf("\n");
    }
    // ����200�� //

    if (is_empty() == true) printf("��ջ\n");
    else printf("����\n");
    // �ж��Ƿ��� //

    return 0;
}