#include <stdio.h>

int main()
{
    int array[20];
    array[0] = array[1] = 1;
    for (int i=2; i<20; i++)
    {
        array[i] = array[i-1] + array[i-2];
    }
    int j=1;
    for (int i=0; i<20; i++)
    {
        printf("%6d", array[i]);
        while(j%5==0)
        {
            printf("\n");
            break;
        }
        j++;
    }
}