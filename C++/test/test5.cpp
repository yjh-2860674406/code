#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int array[10];
    cout << "������10������:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i <10; i++)
    {
        sum += array[i];
    }
    cout << "�ۼӺ� = " << sum << ',' 
    << "ƽ��ֵ = " << sum/10 << endl;
}