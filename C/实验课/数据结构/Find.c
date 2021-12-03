#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct Array {
    // 顺序表结构体
    int* array;
    int length;
}*PtrArray, Array;

void InitArray (PtrArray array) {
    // 初始化顺序表
    array->array = (int*)malloc(array->length*sizeof(int));
}

int FindByOrder (int* array, int length, int elem) {
    // 顺序查找
    for (int i=0; i<length; i++) {
        if (array[i] == elem) return i;
    }
    return -1;
}

int FindByBit (int* array, int length, int elem) {
    // 折半查找
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
    // 交换数组中的两个下标值
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void InsertSort (int* array, int lenght) {
    // 插入排序 O(n^2)
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
    printf("请输入数据（-1表示结束）：\n");
    scanf("%d", &num); getchar();
    while(num != -1) {
        len++;
        nums[len] = num;
        scanf("%d", &num); getchar();
    }
    Array array; array.array = nums; array.length = len;
    int judge = 0; int x;
    while (1) {
        printf("*******请输入要进行的操作（-1退出）：*******\n");
        printf("101 : 查找元素\t102 : 数据排序\t103 : 打印数据\n");
        scanf("%d", &x); getchar();
        switch (x) {
            case -1 : return 0;
            case 101 :
                printf("请输入要查询的元素（-1表示没有该元素）：\n"); scanf("%d", &x); getchar();
                if (judge) {
                    printf("%d 在数据中的位置：%d\n", x, FindByBit(array.array, array.length, x)+1); 
                } else {
                    printf("%d 在数据中的位置：%d\n", x, FindByOrder(array.array, array.length, x)+1); 
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
                printf("输入有误请重新输入！\n");
                break;
        }
    }
}

int main () {
    Screen();
}