#include "Sort.h"
#include <stdlib.h>

int main()
{
    int array[100000];
    int size = sizeof(array)/sizeof(array[0]);
    for (int i=0; i<size; i++)
    {
        array[i] = rand()%7+18;
    }
    InsertSort(array, size);
    for (int i=0; i<size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}