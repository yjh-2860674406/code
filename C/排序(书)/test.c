#include "Sort.h"

int main()
{
    int array[] = {9,8,5,4,2,0};
    int size = sizeof(array)/sizeof(array[0]);
    ShellSort(array, size);
    for (int i=0; i<size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}