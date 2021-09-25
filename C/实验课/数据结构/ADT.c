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
    // ����һ���յ����Ա�
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
    // �������Ա�
    free(array); array = NULL;
}

void ClearList (ptrlist array) {
    // ���óɿձ�
    array->length = 0;
}

int ListEmpty (ptrlist array) {
    // �ж��Ƿ�Ϊ�ձ�
    if (array->length = 0) return FALSE;
    else return TRUE;
}

int ListLenth (ptrlist array) {
    // ��ȡ���Ա�ĳ���
    return array->length;
}

Elem GetElem (ptrlist array, int i) {
    // ���ص�i��Ԫ��
    if (i > array->length) return ERROR;
    else return array->list[i];
}

Elem LocateElem (ptrlist array, Elem e,int compare()) {
    // �ҵ���һ������ compare e ��λ��
    for (int i=0; i < array->length; i++) {
        if (compare(array->list[i]), e) return i;
    }
    return FALSE;
}

int compare (Elem x, Elem y) {
    // �Ƚ�����Ԫ���Ƿ����
    if (x==y) return TRUE; else return FALSE;
}

Elem PtriorElem (ptrlist array, Elem e) {
    // ��ĳ��Ԫ�ص�ǰ��Ԫ��
    if (*(array->list) == e) return FALSE;
    for (int i=1; i<array->length; i++) {
        if (array->list[i] == e) return array->list[i-1];
    }
    return TRUE;
}

Elem NextElem (ptrlist array, Elem e) {
    // ��ĳ��Ԫ�صĺ��Ԫ��
    if (array->list[array->length-1] == e) return FALSE;
    for (int i=0; i<array->length-1; i++) {
        if (array->list[i] == e) return array->list[i+1];
    }
    return TRUE;
}

int ListInsert (ptrlist array, Elem e, int i) {
    // �ڵ� i ��λ�ò��� Ԫ�� e
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
    // ɾ���� i ��Ԫ�ز��� e ����;
    i--;
    *e = L->list[i];
    for (int j=i; j<L->length-1; j++) {
        L->list[j] = L->list[j+1];
    }
    return TRUE;
}

int main () {
    
}