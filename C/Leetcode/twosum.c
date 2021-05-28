#include <stdio.h>
#include <stdlib.h>

int* twoSum (int* nums, int numSize, int target, int* returnSize)
{
    int hash[100];
    for (int i=0; i<100; i++)
    {
        hash[i] = -10;
    }
    for (int i=0; i<numSize; i++)
    {
        if (hash[nums[i]] == -10) hash[target - nums[i]] = i;
        else 
        {
            returnSize[0] = i;
            returnSize[1] = hash[nums[i]];
        }
    }
}

int main()
{
    int* Index = (int*)malloc(8);
    int nums[4] = {2,7,11,15};
    twoSum(nums, 4, 9, Index);
    for (int i=0; i<2; i++)
    {
        printf("%d\t", Index[i]);
    }
}