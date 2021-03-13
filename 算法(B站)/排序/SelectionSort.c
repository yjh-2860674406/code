#include <stdio.h>

void SelectionSort(int* array, int n);


int main()
{
    int list[] = {22,21,1,2,0,23,3};
    int size = sizeof(list)/sizeof(list[0]);
    SelectionSort(list, size);
    for (int i=0; i<size; i++)
    {
        printf("%d\n", list[i]);
    }
    return 0;
}



void SelectionSort(int* array, int n)
{
    int i,j,temp;
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
