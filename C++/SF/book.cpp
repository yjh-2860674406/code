#include <iostream>

using namespace std;

void Swap (int &x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void Perm (int* list, int k, int m) {
    if (k==m) {
        for (int i=0; i<=m; i++) 
            cout << list[i] << ' ';
        cout << endl;
    } else {
        for (int i=k; i<=m; i++) {
            Swap(list[k], list[i]);
            Perm(list, k+1, m);
            Swap(list[k], list[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    int list[3] = {1,2,3};
    Perm(list, 0, 2);
    return 0;
}
