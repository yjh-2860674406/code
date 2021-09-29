#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct AList alist;
typedef alist * ptrlist;
typedef int Elem;

struct AList {
    Elem * list;
    int length;
    int size;   
};
ptrlist InitList ( ) {
    // 构造一个空的线性表
    ptrlist array = (ptrlist)malloc(sizeof(alist));
    if (array == NULL) exit(ERROR);
    else {
        array->length = 1; array->size = 10;
        array->list = (Elem*)malloc(sizeof(Elem));
        // printf("%d\n", array->list[0]);
        // printf("%d\n", array->length); printf("%d\n", array->size);
        return array;
    }
}

void DestroyList (ptrlist array) {
    // 销毁线性表
    free(array); array = NULL;
}

void ClearList (ptrlist array) {
    // 重置成空表
    array->length = 0;
}

int ListEmpty (ptrlist array) {
    // 判断是否为空表
    if (array->length = 0) return FALSE;
    else return TRUE;
}

int ListLenth (ptrlist array) {
    // 获取线性表的长度
    return array->length;
}

Elem GetElem (ptrlist array, int i) {
    // 返回第i个元素
    if (i > array->length) return ERROR;
    else return array->list[i];
}

Elem LocateElem (ptrlist array, Elem e,int compare()) {
    // 找到第一个符合 compare e 的位置
    for (int i=0; i < array->length; i++) {
        if (compare(array->list[i]), e) return i;
    }
    return FALSE;
}

int compare (Elem x, Elem y) {
    // 比较两个元素是否相等
    if (x==y) return TRUE; else return FALSE;
}

Elem PtriorElem (ptrlist array, Elem e) {
    // 找某个元素的前驱元素
    if (*(array->list) == e) return FALSE;
    for (int i=1; i<array->length; i++) {
        if (array->list[i] == e) return array->list[i-1];
    }
    return TRUE;
}

Elem NextElem (ptrlist array, Elem e) {
    // 找某个元素的后继元素
    if (array->list[array->length-1] == e) return FALSE;
    for (int i=0; i<array->length-1; i++) {
        if (array->list[i] == e) return array->list[i+1];
    }
    return TRUE;
}

int ListInsert (ptrlist array, Elem e, int i) {
    // 在第 i 个位置插入 元素 e
    i--;
    if ((array->length) < (array->size)) {
        for (int j=(array->length); j>i; j--) {
            array->list[j] = array->list[j-1];
        }
        array->list[i] = e; array->length += 1;
        return TRUE;
    } else {
        Elem* newbase = (Elem*)realloc(array->list, ((array->length)+10)*sizeof(Elem));
        array->list = newbase;
        for (int j=(array->length); j>i; j--) {
            array->list[j] = array->list[j-1];
        }
        array->list[i] = e; array->length += 1;array->size += 1;
        return TRUE;
    }

}

int ListDelete (ptrlist L, int i, Elem* e) {
    // 删除第 i 个元素并用 e 接收;
    i--;
    *e = L->list[i];
    for (int j=i; j<L->length-1; j++) {
        L->list[j] = L->list[j+1];
    }
    return TRUE;
}


int Screen() {
    ptrlist list = InitList();
    printf("请输入要填入的元素(以-1结尾)：\n");
    int num = 0; int i = 1; scanf("%d", &num); getchar();
    while (num != -1) {
        ListInsert(list, num, i++);
        scanf("%d", &num); getchar();
    }
    int temp = 0; int e = 0;
    while (1) {
        printf("   ****************************************  \n");
        printf("   ********请输入要进行的操作：***********  \n");
        printf("101 添加元素\t102 在第i个位置添加元素\t103 获取元素的前驱元素\n");
        printf("201 获取元素的后继元素\t 202 删除第i个元素\n");
        printf("301 重置表\t302 获取数组长度\t303 打印数组全部元素\n");
        int x=0; scanf("%d", &x); getchar();
        switch (x) {
            case 101 :
                printf("请输入要添加的元素：\n");
                scanf("%d", &temp); ListInsert(list, temp, list->length);
                printf("添加完成！\n");
                break;
            case 102 :
                printf("请输入要添加的元素和元素位置：\n");
                scanf("%d, %d", &temp, &i); getchar();
                ListInsert(list, temp, i); printf("添加成功！\n");
                break;
            case 103 :
                printf("请输入要找的元素：\n");
                scanf("%d", &temp); getchar();
                printf("%d的前驱元素是%d\n", temp, PtriorElem(list, temp));
                break;
            case 201 :
                printf("请输入要找的元素：\n");
                scanf("%d", &temp); getchar();
                printf("%d的后继元素是%d\n", temp, NextElem(list, temp));
                break;
            case 202 :
                printf("请输入要删除的元素的位置：\n");
                scanf("%d", &i); getchar();
                ListDelete(list, i, &e); printf("删除成功！删除的是%d\n", e);
                break;
            case 301 :
                ClearList(list); printf("重置成功！\n"); Screen(); break;
            case 302 :
                printf("数组的长度是：%d\n", ListLenth(list)); break;
            case 303 :
                for (int j=0; j<list->length-1; j++) {
                    if ((j+6)%6==0) printf("\n");
                    printf("%d\t", list->list[j]);
                }
                printf("\n");
                break;
            case 0 : return 0;
            default : printf("请输入错误，请重新输入！\n"); continue;
        }
    }
}

int main () {
    Screen();
}