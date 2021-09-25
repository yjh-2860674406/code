#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define CHECK if (i<1 || i>3) return FALSE;

typedef int Elemtype;
typedef Elemtype * ptrElem; 

 ptrElem InitTriplet (Elemtype v1, Elemtype v2, Elemtype v3) {
    //  ��ʼ����Ԫ��
    ptrElem T = (ptrElem)malloc(3*sizeof(Elemtype));
    if (!T) return FALSE;
    T[0] = v1; T[1] = v2; T[2] = v3;
    return T;
}

void DestroyTriplet (ptrElem T) {
    // ������Ԫ��
    free(T); T = NULL;
}

int Get (ptrElem T, int i, ptrElem e) {
    // ��ȡ��i��Ԫ�ص�e
    CHECK
    *e = T[i-1]; return TRUE;
}

int Put (ptrElem T, int i, Elemtype e) {
    // �ѵ�i������Ϊe
    CHECK
    T[i-1] = e; return TRUE;
}

int IsAscending (ptrElem T) {
    // �ж��Ƿ�����
    if (T[0] < T[1] && T[1] < T[2]) return TRUE;
    else return FALSE;
}

int IsDecending (ptrElem T) {
    // �ж��Ƿ���
    if (T[2] < T[1] && T[1] < T[0]) return TRUE;
    else return FALSE;
}

int Max (ptrElem T, ptrElem e) {
    // �ҵ�����Ԫ��
    if (T[0] > T[1] && T[0] > T[2]) {
        *e = T[0]; return TRUE;
    }
    if (T[1] > T[0] && T[1] > T[2]) {
        *e = T[1]; return TRUE;
    }
    if (T[2] > T[1] && T[2] > T[0]) {
        *e = T[2]; return TRUE;
    }
}

int Min (ptrElem T, ptrElem e) {
    // �ҵ���С��Ԫ��
    if (T[0] < T[1] && T[0] < T[2]) {
        *e = T[0]; return TRUE;
    }
    if (T[1] < T[0] && T[1] < T[2]) {
        *e = T[1]; return TRUE;
    }
    if (T[2] < T[1] && T[2] < T[0]) {
        *e = T[2]; return TRUE;
    }
}

// ��������

int Screen () {
    printf("*******��������Ԫ���������*******\n");
    printf("�������������ݳ�ʼ����Ԫ�飨e1,e2,e3��:\n");
    int x; int y; int z;
    scanf("%d,%d,%d", &x, &y, &z); getchar();
    ptrElem triplet = InitTriplet(x,y,z);
    while (1) {
        printf("\n********��������Ҫ���еĲ���********\n");
        printf("1 ��ȡ��i��Ԫ�أ�2 �޸ĵ�i��Ԫ�أ�3 �ж��Ƿ�Ϊ����4 �ж��Ƿ�Ϊ����\n");
        printf("5 �ҳ�����Ԫ�أ�6 �ҳ���С��Ԫ�أ�7 �ؽ���Ԫ�飬8 ��ӡȫ��Ԫ�أ�9 �˳�\n\n");
        int num; scanf("%d", &num); getchar();
        int e; int i;
        switch (num) {
            case 1 : 
            printf("Ҫ���ĸ�Ԫ�أ�\n");
            scanf("%d", &i); getchar();
            Get(triplet, i, &e);
            printf("��%d��Ԫ�أ�%d\n", i, e);
            break;
            case 2 :
            printf("Ҫ�޸��ĸ�Ԫ�أ�\n");
            scanf("%d", &i); getchar();
            printf("Ҫ�޸ĳ�ʲôֵ��\n");
            scanf("%d", &e); getchar();
            Put(triplet, i, e); printf("�޸ĳɹ���\n");
            break;
            case 3 :
            if (IsAscending(triplet)) printf("������ģ�\n"); 
            else printf("��������ģ�\n"); break;
            case 4 :
            if (IsDecending(triplet)) printf("�ǽ���ģ�\n");
            else printf("���ǽ���ģ�\n"); break;
            case 5 :
            Max(triplet, &e);
            printf("����Ԫ����%d\n", e); break;
            case 6 :
            Min(triplet, &e);
            printf("��С��Ԫ����%d\n", e); break;
            case 7 :
            DestroyTriplet(triplet); Screen(); return 1;
            case 8 :
            printf("��Ԫ�飺%d,%d,%d\n", triplet[0], triplet[1], triplet[2]); break;
            case 9 :
            printf("���˳���\n"); return 1;
            default : 
            printf("��������ȷ�����ַ�Χ��1-8����\n");
            Screen();break;
        }
        
    }
}

int main () {
    Screen();
    return 0;
}