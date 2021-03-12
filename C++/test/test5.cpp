#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int array[10];
    cout << "请输入10个数字:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i <10; i++)
    {
        sum += array[i];
    }
    cout << "累加和 = " << sum << ',' 
    << "平均值 = " << sum/10 << endl;
}