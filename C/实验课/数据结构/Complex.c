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
    // ��ʼ�������ṹ��
    MALLOC
    if (!Com) return FALSE;
    Com->real = i; Com->visual = j; return Com;
}

ptrcom add (ptrcom first, ptrcom second) {
    // �����������ṹ�����
    MALLOC
    Com->real = first->real + second->real;
    Com->visual = first->visual + second->visual;
    return Com;
}

ptrcom sub (ptrcom first, ptrcom second) {
    // �����������ṹ�����
    MALLOC
    Com->real = first->real - second->real;
    Com->visual = first->visual - second->visual;
    return Com;
}

ptrcom mul (ptrcom first, ptrcom second) {
    // �����������ṹ�����
    MALLOC
    Com->real = (first->real*second->real) - (first->visual*second->visual);
    Com->visual = (first->real*second->visual) + (first->visual*second->real);
    return Com;
}

void Print (ptrcom Com) {
    // �Ը�����ʽ��ӡ�ṹ��
    if (Com->visual >= 0) printf("���Ϊ ��%2d+%di\n", Com->real, Com->visual);
    else printf("���Ϊ ��%2d-%di\n", Com->real, -(Com->visual));
}

// ��������
int Screen () {
    while (1) {
        printf("*********�����������*********\n");
        printf("������һ��������real��visual��\n");
        int x; int y;
        scanf("%d,%d", &x, &y); getchar();
        ptrcom first = Initcomplex(x,y);
        printf("��������һ��������real��visual��\n");
        scanf("%d,%d", &x, &y); getchar();
        ptrcom second = Initcomplex(x,y);
        printf("****������Ҫִ�еļ������****\n");
        printf("1 Ϊ��ӣ�2 Ϊ�����3Ϊ��ˣ�0�˳�\n");
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
            printf("�������������1-3\n");
            printf("1 Ϊ��ӣ�2 Ϊ�����3Ϊ���\n");
            continue;
        }

    }
}

int main () {
    Screen();
}