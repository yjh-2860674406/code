#include <iostream>

using namespace std;

void Update (int& x, int y, int z) {
    // 更新最大的值
    if (y > z) x = y;
    else x = z;
}

int getMax (int x, int y) {
    if (x>y) return x;
    else return y;
}

int* getV (int n) {
    // 获得V数组
    cout << "请输入每个物品的价值：" << endl;
    int* v = new int[n];
    for (int i=0; i<n; i++) cin >> v[i];
    return v;
}

int* getW (int n) {
    // 获得W数组
    cout << "请输入每个物品的重量：" << endl;
    int* w = new int[n];
    for (int i=0; i<n; i++) cin >> w[i];
    return w;
}

int* getB (int n) {
    // 获得B数组
    cout << "请输入每个物品的体积：" << endl;
    int* b = new int[n];
    for (int i=0; i<n; i++) cin >> b[i];
    return b;
}

// void Print (int*** matrix, int r, int l, int h) {
//     // 打印矩阵
    
// }

int*** getMatrix (int* v, int* w, int* b, int n, int c, int d) {
    int*** matrix = new int**[c+1];
    for (int i=0; i<=c; i++) {
        matrix[i] = new int*[d+1];
        for (int j=0; j<=d; j++) matrix[i][j] = new int[n+1];
    }

    for (int i=0; i<=c; i++) for (int j=0; j<=d; j++) matrix[i][j][0] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=0; j<=c; j++) {
            for (int k=0; k<=d; k++) {
                if (w[i-1] <= j && b[i-1] <= k) Update(matrix[j][k][i], matrix[j][k][i-1], matrix[j-w[i-1]][k-b[i-1]][i-1] + v[i-1]);
                else matrix[j][k][i] = matrix[j][k][i-1];
            }
        }
    }

    return matrix;    
}

int* getNums (int*** matrix, int* v, int* w, int* b, int n, int c, int d) {
    int* nums = new int[n];
    int x = c, y = d;
    for (int i=n; i>0; i--) {
        if (matrix[x][y][i] - matrix[x][y][i-1]) {
            nums[i-1] = 1;
            x -= w[i-1];
            y -= b[i-1];
        } else nums[i-1] = 0;
    }
    return nums;
}

int main(int argc, char const *argv[]) {
    cout << "请输入物品的个数和负重上限和背包容量：" << endl;
    int n, c, d; // n为个数 c为容量
    cin >> n >> c >> d;
    int* v = getV(n);
    int* w = getW(n);
    int* b = getB(n);
    int*** matrix = getMatrix(v, w, b, n, c, d);
    int* nums = getNums(matrix, v, w, b, n ,c, d);
    cout << "背包能够装价值最多为：" << matrix[c][d][n] << endl;
    cout << "其中装的物品为：" << endl;
    for (int i=0; i<n; i++) cout << " " << i+1 << " 号物体：" << nums[i] << " 个" << endl;
    return 0;
}