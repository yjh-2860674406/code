#include <stdio.h>

void InsertSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
        // 当第 i 个 小于 第 i-1 个时, 启动排序, 直到比下一个大为止.
        {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
        }
    }
}

void ShellSort (int array[], int n)
{
    int temp = n;
    do
    {
        temp = (temp/3)+1;
        for (int i=1; i<n; i+=temp)
        {
            for (int j=i; j>0&&array[j]<array[j-temp]; j-=temp)
            {
                int m = array[j];
                array[j] = array[j-=temp];
                array[j-=temp] = m;
            }            
        }
    } while (temp==1);
    InsertSort(array, n);
}