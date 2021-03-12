#include <iostream>

using namespace std;

void charge (int &y, int &x);

int main ()
{
    int x = 4;
    int y = 3;
    charge (x, y);
    cout << '(' << x << ',' << y << ')' << endl;

}

void charge (int &y, int &x)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}