#include <stdio.h>

int main(int argc, char const *argv[])  {
    int nums[100];
    int min;
    int index;
    for (int i=0; i<100; i++) {
        min = nums[i];
        index = i;
        for (int j=i+1; j<100; j++) {
            if (nums[j] < min) {
                min = nums[j];
                index = j;
            }
        }
        nums[index] = nums[i];
        nums[i] = min;
    }
    return 0;
}