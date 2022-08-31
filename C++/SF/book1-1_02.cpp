#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int* getNums (int n) {
    // 将数字转换成数组
    int* nums = new int[10];
    for (int i=0; i<10; i++) {
        nums[9-i] = ( n % (int)pow(10, i+1) ) / (int)pow(10, i);
    }
    return nums;
}

int translate (int* nums, int l, int r) {
    // 获得数字区间内的大小
    int n = 0;
    int num = 0;
    for (int i=r; i>=l; i--) n += nums[i] * (int)pow(10, num++);
    return n;
}

int getH (int* nums) {
    // 获取最高位的位置
    for (int i=0; i<10; i++) {
        if (nums[i]) return i;
    }
    return 9;
}

int getCouter (int* nums, int n) {
    // 对数组中的每一位进行计算（公式）
    // 直接对 目标数（总页码）进行操作，不需要从 1 ~ n 遍历
    // 时间复杂度 与 总页码 n 无关，只与 n 个有效位数有关
    // 当 n 足够大时，时间复杂度可以相当于 O（1）
    int couter = 0;
    int H = getH(nums);
    if (!n) {
        // 0 有点特殊，只能拉出来单独算
        for (int i=9; i>=H; i--) {
            int h = translate(nums, H, i-1);
            int l = translate(nums, i+1, 9);
            if (nums[i] >= n) couter += h * pow(10, 9-i);
            if (nums[i] == n) couter -= pow(10, 9-i) - l - 1;
        }
    } else {
        // 1~9 可以合并用一段代码算
        for (int i=9; i>=H; i--) {
            int h = translate(nums, H, i-1);
            int l = translate(nums, i+1, 9);
            couter += h * pow(10, 9-i);
            if (nums[i] > n ) couter += pow(10, 9-i);
            if (nums[i] == n ) couter += l + 1;
        }
    }
    return couter;
}

int main(int argc, char const *argv[])
{
    int num = 0;
    cout << "请输入要总页数 n ：" << endl;
    cin >> num;

    int* nums = getNums(num);
    cout << "您输入的数为 ：";
    for (int i=0; i<10; i++) cout << nums[i]; cout << endl;
    cout << "结果为 ：" << endl;
    for (int i=0; i<10; i++) {
        cout << "数字 " << i << " 出现的次数为 ：" << getCouter(nums, i) << endl;
    }
    return 0;
}
