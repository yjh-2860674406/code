#include <stdio.h>

void change (int* n, int* m)
{
    if (*n > *m) *m = *n;
}

void Max (int n, int m, int array[n][m])
{
    int num=-200;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            change(&array[i][j], &num);
        }
    }
    printf("Max element : %d\n", num);
}

int main()
{
    int array[3][4] = {{1,2,3,4},{9,8,7,6},{-10,10,-5,2}};
    Max(3,4,array);
}