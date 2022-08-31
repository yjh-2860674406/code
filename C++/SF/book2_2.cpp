#include <iostream>

using namespace std;

int BinarySearch1 (int* nums, const int x, int n) {
    int left = 0;
    int right = n-1;
    while (left<=right) {
        int mid = (left+right)/2;
        if (x == nums[mid]) return mid;
        else if (x > nums[mid]) left = mid;
        else right = mid;
    } return -1;
}

int BinarySearch2 (int* nums, const int x, int n) {
    int left = 0;
    int right = n-1;
    while (left<right-1) {
        int mid = (left+right)/2;
        if (x < nums[mid]) right = mid;
        else left = mid;
    }
    if (x == nums[left]) return left;
    else return -1;
}

int BinarySearch3 (int* nums, const int x, int n) {
    int left = 0;
    int right = n-1;
    while (left+1 != right) {
        int mid = (left+right)/2;
        if (x >= nums[mid]) left = mid;
        else right = mid;
    }
    if (x == nums[left]) return left;
    else return -1;
}

int BinarySearch4 (int* nums, const int x, int n) {
    if (n>0 && x>=nums[0]) {
        int left = 0; int right = n-1;
        while (left < right) {
            int mid = (left + right)/2;
            if (x < nums[mid]) right = mid-1;
            else left = mid;
        }
        if (x==nums[left]) return left;
    }
    return -1;
}

int BinarySearch5 (int* nums, const int x, int n) {
    if (n > 0 && x >= nums[0]) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (x < nums[mid]) right = mid - 1;
            else left = mid;
        }
        if (x == nums[left]) return left;
    }
    return -1;
}

int BinarySearch6 (int* nums, const int x, int n) {
    if (n > 0 && x >= nums[0]) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (x < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        if (x == nums[left]) return left;
    }
    return -1;
}

int BinarySearch7 (int* nums, const int x, int n) {
    if (n > 0 && x >= nums[0]) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (x < nums[mid]) right = mid;
            else left = mid;
        }
        if (x == nums[left]) return left;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int nums[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for (int i=0; i<16; i++) cout << BinarySearch7(nums, i, 16) << endl;
    cout << BinarySearch5(nums, 20, 16) << endl ;
    return 0;
}
