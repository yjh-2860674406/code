#include <stdio.h>
#include <stdlib.h>

int* getNums (int num) {
  int length = ( (1 + num) * num ) / 2;
  int* nums = (int*)malloc(sizeof(int)*length);
  return nums; 
}

void pull (int* nums, int num) {
  int l = ( (1 + num) * num ) / 2;
  for (int i=0; i<l; i++) {
    scanf("%d", &nums[i]);
  }
}

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int* nums = getNums(5);
  pull(nums, 5);
  for (int i=0; i<15; i++) {
    printf("%d\n", nums[i]);
  }
  return 0;
}