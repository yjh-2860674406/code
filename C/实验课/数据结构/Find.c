#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct Array {
    // ˳���ṹ��
    int* array;
    int length;
}*PtrArray, Array;

void InitArray (PtrArray array) {
    // ��ʼ��˳���
    array->array = (int*)malloc(array->length*sizeof(int));
}

int FindByOrder (int* array, int length, int elem) {
    // ˳�����
    for (int i=0; i<length; i++) {
        if (array[i] == elem) return i;
    }
    return -1;
}

int FindByBit (int* array, int length, int elem) {
    // �۰����
    int i = 0; int j = length-1; int m = (j+i)/2;
    while (i<j) {
        if (array[m] > elem) {
            j = m;
            m = (j+i)/2;
        }
        else if (array[m] < elem) {
            i = m;
            m = (j+i)/2;
        } else return m;
    }
    return -1;
}

void Swap(int* array, int i, int j) {
    // ���������е������±�ֵ
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void InsertSort (int* array, int lenght) {
    // �������� O(n^2)
    for (int i = 1; i<lenght; i++) {
        if (array[i] < array[i-1]) {
            for (int j = i; j>=0 ; j--) {
                if (array[j] < array[j-1]) {
                    Swap(array, j, j-1);
                } else break;
            }
        }
    }
}

int Screen () {
    int num;
    int len=-1;
    int nums[50];
    printf("���������ݣ�-1��ʾ��������\n");
    scanf("%d", &num); getchar();
    while(num != -1) {
        len++;
        nums[len] = num;
        scanf("%d", &num); getchar();
    }
    Array array; array.array = nums; array.length = len;
    int judge = 0; int x;
    while (1) {
        printf("*******������Ҫ���еĲ�����-1�˳�����*******\n");
        printf("101 : ����Ԫ��\t102 : ��������\t103 : ��ӡ����\n");
        scanf("%d", &x); getchar();
        switch (x) {
            case -1 : return 0;
            case 101 :
                printf("������Ҫ��ѯ��Ԫ�أ�-1��ʾû�и�Ԫ�أ���\n"); scanf("%d", &x); getchar();
                if (judge) {
                    printf("%d �������е�λ�ã�%d\n", x, FindByBit(array.array, array.length, x)+1); 
                } else {
                    printf("%d �������е�λ�ã�%d\n", x, FindByOrder(array.array, array.length, x)+1); 
                }
                break;
            case 102 : 
                InsertSort(array.array, array.length);
                judge = 1;
                break;
            case 103 : 
                for (int i=0; i<array.length; i++) {
                    printf("%d  ", array.array[i]);
                } printf("\n");
                break;
            default : 
                printf("�����������������룡\n");
                break;
        }
    }
}

int main () {
    Screen();
}