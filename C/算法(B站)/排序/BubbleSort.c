#include <stdio.h>

void BubbleSort (int* array ,int n);

int main()
{
    int list[] = {1,2,5,4,3,8,7,6};
    int size = sizeof(list)/sizeof(list[0]);
    BubbleSort(list, size);
    for (int i=0; i<size; i++)
    {
        printf("%d\n", list[i]);
    }
    return 0;
}

void BubbleSort (int* array, int n)
{
    int i,j,temp;
    for (j=n-1; j>0; j--)
        for (i=0; i<j; i++)
        {
            if (array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
}

