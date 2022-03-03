#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void bubble_sort (int* array, int length) {
    int index = 0;
    for (int i=length-1; i>= 1; i--) {
        for (int j=0; j<index; j++) {
            if (array[j]>array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                index = j+1;
            }
        }
    }
}