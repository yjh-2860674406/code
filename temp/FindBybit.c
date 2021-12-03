#include <stdio.h>

int FindByBit (int* array, int l, int r, int e) {
    int mid = (int)((l+r)/2);
    if (l == r) {
        return -1;
        // 找不到就返回-1
    } else if (array[mid] == e) {
        return mid;
        // 找到返回下标
    } else if (array[mid] < e) {
        // 递归查找右半部分
        FindByBit(array, mid, r, e);
    } else {
        // 递归查找左半部分
        FindByBit(array, l, mid, e);
    }
}

int main () {
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int res = FindByBit(array, 0, 9, 1);
    printf("%d\n", res);
}