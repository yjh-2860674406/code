#include <iostream>

using namespace std;

void Swap (int& x, int& y) {
    // ����������
    int temp = x;
    x = y; 
    y = temp;
}

int Cmopare (int x, int y, int z) {
    // �Ƚ����������ֵ
    if (x > y) 
        if (x > z) return x;
        else return z;
    else 
        if (y > z) return y;
        else return z;
}

int getMode (int* nums, int l, int r, int& mode) {
    // �ݹ�ͷ��λ������
    if (l > r) return 0; // �˳�����
    int l_const = l, r_const = r;
    int x = nums[l++];
    int k = 0;

    while (l <= r) {
        // ���� ���� partition �Ĳ���
        if (nums[l] > x) {
            // �����򽻻� l �� r  
            Swap(nums[l], nums[r]);
            r--; l--;
        } else if (nums[l] == x) {
            // �����򽻻� l �� k 
            // ��x������һ����k++
            Swap(nums[k+l_const+1], nums[l]);
            k++;
        }   // С����ɶҲ����
        l++;
        // ��ָ�� ����ǰ��
    }
    
    k++;

    int l_max = 0; int r_max = 0; int l_mode = 0; int r_mode = 0;
    // �ȳ�ʼ��Ϊ0 

    if (k < l-k-l_const) l_max = getMode(nums, k+l_const, l-1, l_mode);
    // �����ߵĳ��ȴ��� ��ǰ��k �п��ܴ����ظ�������k����� ��ݹ�
    if (k < r_const-l+1) r_max = getMode(nums, l, r_const, r_mode);
    // ����ұߵĳ��ȴ��� ��ǰ��k �п��ܴ����ظ�������k����� �ҵݹ�

    int max = Cmopare(l_max, r_max, k);
    // ��� �ظ� ������������ �Ĵ���

    if (max == k) mode = x;             
    else if (max == l_max) mode = l_mode;
    else mode = r_mode;
    // �����Ӧ������

    return max;
}

int main(int argc, char const *argv[]) {
    cout << "********����********" << endl;
    int length = 0;
    cin >> length;

    cout << "********����********" << endl;
    int* nums = new int[length];
    for (int i=0; i<length; i++) cin >> nums[i];

    int mode = 0;
    int couter = getMode(nums, 0, length-1, mode);

    cout << "********���********" << endl;
    cout << mode << endl;
    cout << couter << endl;
    
    return 0;
}