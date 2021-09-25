#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* oula (int n)
{ 
    int m=0;
    int* a = malloc(n*sizeof(int));

    for (int i=0; i<n; i++)
    {
        a[i] = 0;
    }
    for (int i=2; i<n; i++)
    {
        if (n%i == 0 && a[i] == 0)
        {
            /* 7s 700000000
            int j = i;
            while (j<n+1)
            {
                if (a[j] == 1)
                {
                    j+=i;
                    continue;
                }
                else 
                {
                    a[j] = 1;
                    j+=i;
                    continue;
                }
            }
            */
           /* 7s 700000000
            for (int j=i; j<n+1; j+=i)
            {
                a[j] = 1;
            }
            */
            for (int j=i; j<n+1; j+=i)
            {
                a[j] = 1;
            }
        }
    }

    for (int i=1; i<n+1; i++)
    {
        if (a[i] != 1)
        {
            // printf("%d\n", i);
            m++;
        }
    }
    printf("与%d互素的个数是:%d\n", n, m);
}

int main()
{
    int n=0;
    int *b;
    printf("请输入一个数:\n");
    scanf("%d", &n);
    time_t start, end;
    start = time(NULL);
    oula(n);
    end = time(NULL);
    printf("该算法花费的时间为:%fs\n", difftime(end, start));
}