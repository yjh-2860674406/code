#include <stdio.h>
#include <stdlib.h>

void check (int* array, int n, int temp[])
{
    for (int i=0; i<n; i++)
    {
        temp[array[i]] ++;
    }
}

int main()
{
    int n = 500000;
    int array[n];
    for (int i=0; i<n; i++)
    {
        array[i] = rand()%7+18;
    }
    int temp[30];
    for (int i=0; i<30; i++)
    {
        temp[i] = 0;
    }
    check(array, n, temp);
    for (int i=0; i<30; i++)
    {
        printf("%d:%d\n", i, temp[i]);
    }
}