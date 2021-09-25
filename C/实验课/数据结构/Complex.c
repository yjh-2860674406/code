#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define MALLOC ptrcom Com = (ptrcom)malloc(sizeof(struct complex));

struct complex {
    int real;
    int visual;
};

typedef struct complex* ptrcom;

ptrcom Initcomplex (int i, int j) {
    // 初始化复数结构体
    MALLOC
    if (!Com) return FALSE;
    Com->real = i; Com->visual = j; return Com;
}

ptrcom add (ptrcom first, ptrcom second) {
    // 将两个复数结构体相加
    MALLOC
    Com->real = first->real + second->real;
    Com->visual = first->visual + second->visual;
    return Com;
}

ptrcom sub (ptrcom first, ptrcom second) {
    // 将两个复数结构体相减
    MALLOC
    Com->real = first->real - second->real;
    Com->visual = first->visual - second->visual;
    return Com;
}

ptrcom mul (ptrcom first, ptrcom second) {
    // 将两个复数结构体相乘
    MALLOC
    Com->real = (first->real*second->real) - (first->visual*second->visual);
    Com->visual = (first->real*second->visual) + (first->visual*second->real);
    return Com;
}

void Print (ptrcom Com) {
    // 以复数形式打印结构体
    if (Com->visual >= 0) printf("结果为 ：%2d+%di\n", Com->real, Com->visual);
    else printf("结果为 ：%2d-%di\n", Com->real, -(Com->visual));
}

// 交互界面
int Screen () {
    while (1) {
        printf("*********复数计算界面*********\n");
        printf("请输入一个复数（real，visual）\n");
        int x; int y;
        scanf("%d,%d", &x, &y); getchar();
        ptrcom first = Initcomplex(x,y);
        printf("请再输入一个复数（real，visual）\n");
        scanf("%d,%d", &x, &y); getchar();
        ptrcom second = Initcomplex(x,y);
        printf("****请输入要执行的计算操作****\n");
        printf("1 为相加，2 为相减，3为相乘，0退出\n");
        int num; scanf("%d", &num); getchar();
        switch(num) {
            case 1 :
            Print(add(first, second)); break;
            case 2 :
            Print(sub(first, second)); break;
            case 3 :
            Print(mul(first, second)); break;
            case 0:
            return 1;
            default :
            printf("输入错误，请输入1-3\n");
            printf("1 为相加，2 为相减，3为相乘\n");
            continue;
        }

    }
}

int main () {
    Screen();
}