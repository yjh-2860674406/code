#include <iostream>

using namespace std;

void getMode (int* nums, int length) {
    int hash[10000];
    for (int& i : hash) i = 0; 
    for (int i=0; i<length; i++) hash[nums[i]]++;
    int max = hash[0]; int index = 0;
    for (int i=1; i<10000; i++) {
        if (hash[i] > max) {
            max = hash[i];
            index = i;
        }
    } 
    cout << index << endl;
    cout << max << endl;
}


int main(int argc, char const *argv[])
{
    int nums[8] = {1,2,2,2,3,3,5,6};
    getMode(nums, 8);
    return 0;
}
