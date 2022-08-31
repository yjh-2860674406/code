#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int* getNums (int n) {
    // 把一个数拆成数组
    int* nums = new int[10];
    for (int i=9; i>=0; i--) {
        nums[i] = ( n % (int)pow(10, 9-i+1) ) / (int)pow(10, 9-i);
    }
    return nums;
}

int getH (int* nums) {
    // 获得最高位的位置
    for (int i=0; i<10; i++) {
        if (nums[i]) return i;
    }
    return 9;
}

int* foreach (int n) {
    // 遍历从 1 ~ n，获取数字的和
    int* result = new int[10];
    for (int i=0; i<10; i++) result[i] = 0;
    int* nums; int H = 0;
    for (int i=1; i<=n; i++) {
        // 遍历从 1 ~ n
        nums = getNums(i);
        // 获取相应数字的每一位的数
        H = getH(nums);
        // 获取最高位的位置
        for (int j=H; j<10; j++) result[nums[j]] += 1;
        // nums[j] 为 i 的其中一位的数字，相对应的 result 自增 1 计数
        delete(nums);  // 释放空间
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int num = 0;
    cout << "请输入要总页数 n ：" << endl;
    cin >> num;

    int *nums = getNums(num);
    cout << "您输入的数为 ：";
    for (int i = 0; i < 10; i++)
        cout << nums[i];
    cout << endl;
    cout << "结果为 ：" << endl;

    int* result = foreach(num);
    for (int i = 0; i < 10; i++)
    {
        cout << "数字 " << i << " 出现的次数为 ：" << result[i] << endl;
    }
    return 0;
}
