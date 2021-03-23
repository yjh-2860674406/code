#include <stdio.h>

void InsertSort (int *array, int n);

int main()
{
    int array[] = {1,2,3,7,6,5,4,9,8,1};
    int size = sizeof(array)/sizeof(array[0]);
    InsertSort(array, size);
    for (int i=0; i<size; i++)
        printf("%d\n", array[i]);
    return 0;
}

void InsertSort (int *array, int n)
{
    for (int i=1; i<n; i++)
        for (int j=i; j>0 && array[j] < array[j-1]; j--)
            {
                int temp;
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        
}