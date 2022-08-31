#include <iostream>

using namespace std;

void Swap (int& x, int& y) {
    // 交换两个数
    int temp = x;
    x = y; 
    y = temp;
}

int Cmopare (int x, int y, int z) {
    // 比较三者中最大值
    if (x > y) 
        if (x > z) return x;
        else return z;
    else 
        if (y > z) return y;
        else return z;
}

int getMode (int* nums, int l, int r, int& mode) {
    // 递归和分治获得众数
    if (l > r) return 0; // 退出条件
    int l_const = l, r_const = r;
    int x = nums[l++];
    int k = 0;

    while (l <= r) {
        // 进行 类似 partition 的操作
        if (nums[l] > x) {
            // 大于则交换 l 与 r  
            Swap(nums[l], nums[r]);
            r--; l--;
        } else if (nums[l] == x) {
            // 等于则交换 l 与 k 
            // 把x放置在一起且k++
            Swap(nums[k+l_const+1], nums[l]);
            k++;
        }   // 小于则啥也不干
        l++;
        // 左指针 向右前进
    }
    
    k++;

    int l_max = 0; int r_max = 0; int l_mode = 0; int r_mode = 0;
    // 先初始化为0 

    if (k < l-k-l_const) l_max = getMode(nums, k+l_const, l-1, l_mode);
    // 如果左边的长度大于 当前的k 有可能存在重复次数比k多的数 左递归
    if (k < r_const-l+1) r_max = getMode(nums, l, r_const, r_mode);
    // 如果右边的长度大于 当前的k 有可能存在重复次数比k多的数 右递归

    int max = Cmopare(l_max, r_max, k);
    // 获得 重复 次数最多的众数 的次数

    if (max == k) mode = x;             
    else if (max == l_max) mode = l_mode;
    else mode = r_mode;
    // 获得相应的众数

    return max;
}

int main(int argc, char const *argv[]) {
    cout << "********输入********" << endl;
    int length = 0;
    cin >> length;

    cout << "********数组********" << endl;
    int* nums = new int[length];
    for (int i=0; i<length; i++) cin >> nums[i];

    int mode = 0;
    int couter = getMode(nums, 0, length-1, mode);

    cout << "********输出********" << endl;
    cout << mode << endl;
    cout << couter << endl;
    
    return 0;
}