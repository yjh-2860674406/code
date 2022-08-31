#include <iostream>
#include <math.h>
#include <bitset>
#include <string>

using namespace std;

typedef struct Gray {
    string* ss; // 用字符串表示格雷码（二进制），主要是空间小
    int length; // 格雷码的个数
}Gray, *PtrGray;

PtrGray getGray (int n) {
    if (n == 1) {
        // 递归退出的时候，即一位格雷码：0，1
        PtrGray gray = new Gray;
        gray->ss = new string[2];
        gray->length = 2;
        gray->ss[0] = "0", gray->ss[1] = "1"; 
        return gray;
    } else {
        // n 位格雷码有 2^n 个，所以需要长度为 2^n 的数组
        int length = (int)pow(2,n);
        PtrGray gray = getGray(n-1);
        // 递归获得 n-1 位的格雷码
        string* ss = new string[length];
        for (int i=0; i<gray->length; i++) {
            ss[i] = gray->ss[i]; ss[i].insert(0, "0");
            // n 位格雷码的前 2^(n-1) 位可以视作 n-1 位格雷码的前面加一个 0
            ss[i+gray->length] = gray->ss[gray->length-i-1]; ss[i+gray->length].insert(0, "1");
            // n 位格雷码的后 2^(n-1) 位可以视作 n-1 位格雷码的前面加一个 1 注：顺序相反！！！
        }
        gray->ss = ss; gray->length = length; // 更新格雷码结构体
        return gray;
    }
}

int main(int argc, char const *argv[])
{
    PtrGray gray = getGray(6);
    for (int i=0; i<gray->length; i++) cout << gray->ss[i] << endl;
    return 0;
}
