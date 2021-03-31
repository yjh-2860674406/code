#include <iostream>

using namespace std;

template <class T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a=3;
    int b=4;
    Swap(a,b);
    cout << a << b << endl;
}