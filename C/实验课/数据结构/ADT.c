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

ptrlist InitList (ptrlist array) {
    // 构造一个空的线性表
    array = (ptrlist)malloc(10*sizeof(alist));
    if (array == NULL) exit(ERROR);
    else {
        array->length = 0; array->size = 10;
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

int main () {
    
}