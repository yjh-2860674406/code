#include <stdio.h>

int fei (int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else 
    {
        return (fei (n-1) + fei (n-2));
    }
}

int main()
{
    for (int i=1; i<31; i++)
    {
        int n = fei(i);
        printf("%d\t", n);
        if (i%5 == 0)
        {
            printf("\n");
        }
    }
}