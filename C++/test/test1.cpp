#include <iostream>

using namespace std;

int main ()
{
    int sum = 0;

    cout << "������һ��������������Ŀ�Ŀո�:";

    int i;
    while (cin >> i)
    {
        sum += i;
        while (cin.peek() == ' ')
        {
            cin.get();
        }
        if (cin.peek() == '\n')
        {
            break;
        }
    }

    cout << "�����:" << sum << endl;

    return 0;
    
}