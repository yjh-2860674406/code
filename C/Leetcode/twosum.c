#include <stdio.h>
#include <stdlib.h>

int* twoSum (int* nums, int numSize, int target, int* returnSize)
{
    returnSize = (int*)malloc(2*sizeof(int));
    int hash[100];
    for (int i=0; i<100; i++) hash[i] = -1;
    for (int i=0; i<numSize; i++)
    {
        if (hash[nums[i]] != -1) 
        {
            returnSize[0] = hash[nums[i]];
            returnSize[1] = i;
            return returnSize;
        }
        else hash[target-nums[i]] = i;
    }
}

int main()
{
    int nums[4] = {2,7,11,15};
    int* returnSize;
    int* p = twoSum(nums, 4, 9, returnSize);
    printf("%d,%d\n", p[0], p[1]);
}