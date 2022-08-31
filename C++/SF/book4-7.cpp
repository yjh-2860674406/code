#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> getBest (int s, vector<int> q) {
    // 获得最优解
    int n = q.size();
    // 顾客的数量
    vector<vector<int>> best;
    // 将要返回的最优解

    for (int i=0; i<s; i++) {
        // 最优解包含s个队列
        vector<int> v;
        best.push_back(v);
    }

    sort(q.begin(), q.end());
    // 顾客需要服务时间最短排序

    for (int i=0; i<n; i++) {
        best[i%s].push_back(q[i]);
        // 逐个添加进最优解中
    }
    return best;
    // 返回最优解
}

int getRes (vector<vector<int>> best, int n) {
    int s = best.size();
    // s条队列
    int res = 0;
    // 结果
    for (int i=0; i<s; i++) {
        int num = best[i].size();
        // 第i条队列的长度
        for (int j=0; j<num; j++) {
            // 通过数学公式求顾客等待时间
            res += best[i][j] * (num-j);
        }
    }
    return res/n;
    // 返回平均等待时间
}

int main(int argc, char const *argv[]) {
    vector<int> q;
    int s, n;
    cin >> n >> s;
    // 获得输入
    int x;
    for (int i=0; i<n; i++) {
        // 获得输入
        cin >> x;
        q.push_back(x);
    }
    vector<vector<int>> best = getBest(s, q);
    // 获取最优解

    cout << "排队情况:" << endl;
    for (int i=0; i<s; i++) {
        // 输出最优解
        cout << "第 " << i << " 条队: ";
        for (int j=0; j<best[i].size(); j++) {
            cout << best[i][j] << " ";
        }
        cout << endl;
    }
    cout << "最短平均等待时间: ";
    cout << getRes(best, n) << endl;
    // 输出最优值
    return 0;
}
