#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

void getGray (string* list, int l, int r, bool tag) {
    if (l+1 == r) {
        if (tag) { list[l] += "0"; list[r] += "1"; } // 正序 01
        else { list[l] += "1" ; list[r] += "0"; }    // 逆序 10
    } else {
        // 递归
        getGray(list, l, (l+r)/2, 1);                // 分治 左半部分 正序 000……111
        getGray(list, ((l+r)/2)+1, r, 0);            // 分治 右半部分 逆序 111……000
        
        if (tag) {
            // 分治的具体实现方式
            for (int i=l; i<=(l+r)/2; i++) list[i] = "0" + list[i]; 
            for (int i=(l+r)/2+1; i<=r; i++) list[i] = "1" + list[i];
        } else {
            for (int i=l; i<=(l+r)/2; i++) list[i] = "1" + list[i];
            for (int i=(l+r)/2+1; i<=r; i++) list[i] = "0" + list[i];
        }

    }
}

int main(int argc, char const *argv[]) {
    int n = 0;
    cout << "请输入您要获得的格雷码的位数：" << endl;
    cin >> n;
    int length = (int)pow(2,n);
    string list[length];
    getGray(list, 0, --length, 1);
    cout << "结果：" << endl;
    for (int i=0; i<=length; i++) cout << list[i] << endl;
    return 0;
}