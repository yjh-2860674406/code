#include <iostream>

using namespace std;

int Pow (int x, int n) {
    if (n == 1) return x;
    return x*Pow(x, n-1);
}

int main(int argc, char const *argv[]) {
    cout << Pow(3,5) << endl;
    return 0;
}

