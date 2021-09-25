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
        printf("空栈！\n");
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
    // 清空堆栈 //

    if (is_empty() == true) printf("空栈\n");
    else printf("不空\n");
    // 判断是否清空完 //

    for (int i=0; i<201; i++) stack_push(i);
    int pop = stack_pop();
    // 将0到199 推入栈 //

    if (is_full() == true) printf("满栈\n");
    else printf("没满\n");
    // 判断有没有满 //

    for (int i=0; i<STACKSIZE; i++)
    {
        printf("%d\t", stack_pop());
        if ((i+1)%5 == 0) printf("\n");
    }
    // 弹出200次 //

    if (is_empty() == true) printf("空栈\n");
    else printf("不空\n");
    // 判断是否弹完 //

    return 0;
}