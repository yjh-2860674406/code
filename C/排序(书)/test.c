#include "Sort.h"

int main()
{
    int array[] = {1,3,54,32,76,23,56,83,258,43,768};
    int size = sizeof(array)/sizeof(array[0]);
    ShellSort(array, size);
    for (int i=0; i<size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}