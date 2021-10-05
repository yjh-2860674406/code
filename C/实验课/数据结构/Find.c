#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

int FindByOrder (int* array, int length, int elem) {
    for (int i=0; i<length; i++) {
        if (array[i] == elem) return i;
    }
    return -1;
}

int FindByBit (int* array, int length, int elem) {
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
}

int main () {
    int* array = (int*)malloc(100000000*sizeof(int));
    for (int i=0; i<100000000; i++) array[i] = i;
    int index = FindByBit(array, 100000000, 80000000);
    printf("%d\n", index);
}