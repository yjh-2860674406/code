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
    //  初始化三元组
    ptrElem T = (ptrElem)malloc(3*sizeof(Elemtype));
    if (!T) return FALSE;
    T[0] = v1; T[1] = v2; T[2] = v3;
    return T;
}

void DestroyTriplet (ptrElem T) {
    // 销毁三元组
    free(T); T = NULL;
}

int Get (ptrElem T, int i, ptrElem e) {
    // 获取第i个元素到e
    CHECK
    *e = T[i-1]; return TRUE;
}

int Put (ptrElem T, int i, Elemtype e) {
    // 把第i个数改为e
    CHECK
    T[i-1] = e; return TRUE;
}

int IsAscending (ptrElem T) {
    // 判断是否升序
    if (T[0] < T[1] && T[1] < T[2]) return TRUE;
    else return FALSE;
}

int IsDecending (ptrElem T) {
    // 判断是否降序
    if (T[2] < T[1] && T[1] < T[0]) return TRUE;
    else return FALSE;
}

int Max (ptrElem T, ptrElem e) {
    // 找到最大的元素
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
    // 找到最小的元素
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

// 交互界面

int Screen () {
    printf("*******以下是三元组操作界面*******\n");
    printf("请输入三个数据初始化三元组（e1,e2,e3）:\n");
    int x; int y; int z;
    scanf("%d,%d,%d", &x, &y, &z); getchar();
    ptrElem triplet = InitTriplet(x,y,z);
    while (1) {
        printf("\n********请输入你要进行的操作********\n");
        printf("1 获取第i个元素，2 修改第i个元素，3 判断是否为升序，4 判断是否为降序\n");
        printf("5 找出最大的元素，6 找出最小的元素，7 重建三元组，8 打印全部元素，9 退出\n\n");
        int num; scanf("%d", &num); getchar();
        int e; int i;
        switch (num) {
            case 1 : 
            printf("要找哪个元素？\n");
            scanf("%d", &i); getchar();
            Get(triplet, i, &e);
            printf("第%d个元素：%d\n", i, e);
            break;
            case 2 :
            printf("要修改哪个元素？\n");
            scanf("%d", &i); getchar();
            printf("要修改成什么值？\n");
            scanf("%d", &e); getchar();
            Put(triplet, i, e); printf("修改成功！\n");
            break;
            case 3 :
            if (IsAscending(triplet)) printf("是升序的！\n"); 
            else printf("不是升序的！\n"); break;
            case 4 :
            if (IsDecending(triplet)) printf("是降序的！\n");
            else printf("不是降序的！\n"); break;
            case 5 :
            Max(triplet, &e);
            printf("最大的元素是%d\n", e); break;
            case 6 :
            Min(triplet, &e);
            printf("最小的元素是%d\n", e); break;
            case 7 :
            DestroyTriplet(triplet); Screen(); return 1;
            case 8 :
            printf("三元组：%d,%d,%d\n", triplet[0], triplet[1], triplet[2]); break;
            case 9 :
            printf("已退出！\n"); return 1;
            default : 
            printf("请输入正确的数字范围（1-8）：\n");
            Screen();break;
        }
        
    }
}

int main () {
    Screen();
    return 0;
}