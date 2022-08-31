#include <iostream>

using namespace std;

int Update (int& x, int y, int z) {
    // 更新最大的值
    if (x > y) {
        if (z > x) {
            x = z;
            return 1;
        }
    } else {
        if (y > z) {
            x = y;
            return 0;
        }
        else {
            x = z;
            return 1;
        }
    }
    return 0;
}

int** getMatrix (int* v, int* w, int c, int n, int* nums) {
    // 获得最大收益
    int** matrix = new int*[c+1];
    for (int i=0; i<=c; i++) matrix[i] = new int[n+1];
    for (int i=0; i<=c; i++) for (int j=0; j<n; j++) matrix[i][j] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=0; j<=c; j++) {
            int k = 1;
            do {
                if (w[i-1]*k <= j) {
                    if (Update(matrix[j][i], matrix[j-(k-1)*w[i-1]][i-1], matrix[j-w[i-1]*k][i-1]+v[i-1]*k)) {
                        nums[i-1] = k;
                    }
                }
                else {
                    matrix[j][i] = matrix[j][i-1];
                    break;
                }
                k++;
            } while (k<=(j/w[i-1]));
        }
    }
    return matrix;
}

void Print (int** matrix, int r, int l) {
    // 打印矩阵
    for (int i=1; i<=r; i++) {
        for (int j=0; j<=l; j++) {
            cout << matrix[j][i] << "\t";
        }
        cout << endl;
    }
}

void getNums (int* w, int* v, int n, int c, int* nums) {
    // 获得选择物体的个数
    int index = c;
    for (int i=n-1; i>=0; i--) {
        // int x = matrix[index][i+1] - matrix[index][i];
        if (nums[i]) {
            int back = w[i] * nums[i];
            for (int j=0; j<i; j++) {
                if ((nums[j] - (back / w[j])) < 0) nums[j] = 0;
                else nums[j] -= back / w[j];
            }
        }
    }
}

int* getV (int n) {
    // 获得V数组
    cout << "请输入每个物体的价值：" << endl;
    int* v = new int[n];
    for (int i=0; i<n; i++) cin >> v[i];
    return v;
}

int* getW (int n) {
    // 获得W数组
    cout << "请输入每个物体的重量：" << endl;
    int* w = new int[n];
    for (int i=0; i<n; i++) cin >> w[i];
    return w;
}

int main(int argc, char const *argv[]) {
    cout << "请输入物品的个数和背包容量：" << endl;
    int n, c; // n为个数 c为容量
    cin >> n >> c;
    int* v = getV(n);
    int* w = getW(n);
    int* nums = new int[n];
    int** matrix = getMatrix(v, w, c, n, nums);
    Print(matrix, n, c);
    getNums(w, v, n, c, nums);
    cout << "背包能够装价值最多为：" << matrix[c][n] << endl;
    cout << "其中装的物品为：" << endl;
    for (int i=0; i<n; i++) cout << " " << i+1 << " 号物体：" << nums[i] << " 个" << endl;
    return 0;
}