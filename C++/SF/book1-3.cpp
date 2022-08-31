#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

int getDiv (int n) {
    int x = (int)pow(n, 0.5);
    int sum = 0;
    for (int i=1; i <= x; i++) {
        if (!(n%i)) {
            sum += 2;
        }
    }
    if (pow(x,2)==n) sum -= 1;
    return sum;
}

int* getArray () {
    int* array = new int[2];
    cin >> array[0] >> array[1];
    return array;
}

int findMax_Num (int* nums, int l) {
    int max = 0;
    for (int i=0; i<l; i++) {
        if (nums[i] >= max) max = nums[i];
    }
    return max;
}

int findMax_Div () {
    int* array = getArray();
    int* divs = new int[array[1]-array[0] + 1];
    for (int i=array[0]; i<=array[1]; i++) {
        divs[i-array[0]] = getDiv(i);
    }
    return findMax_Num(divs, array[1]-array[0] + 1);
}

int main(int argc, char const *argv[])
{
    cout << findMax_Div() << endl ;
    return 0;
}
