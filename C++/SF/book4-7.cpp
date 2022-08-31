#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> getBest (int s, vector<int> q) {
    // ������Ž�
    int n = q.size();
    // �˿͵�����
    vector<vector<int>> best;
    // ��Ҫ���ص����Ž�

    for (int i=0; i<s; i++) {
        // ���Ž����s������
        vector<int> v;
        best.push_back(v);
    }

    sort(q.begin(), q.end());
    // �˿���Ҫ����ʱ���������

    for (int i=0; i<n; i++) {
        best[i%s].push_back(q[i]);
        // �����ӽ����Ž���
    }
    return best;
    // �������Ž�
}

int getRes (vector<vector<int>> best, int n) {
    int s = best.size();
    // s������
    int res = 0;
    // ���
    for (int i=0; i<s; i++) {
        int num = best[i].size();
        // ��i�����еĳ���
        for (int j=0; j<num; j++) {
            // ͨ����ѧ��ʽ��˿͵ȴ�ʱ��
            res += best[i][j] * (num-j);
        }
    }
    return res/n;
    // ����ƽ���ȴ�ʱ��
}

int main(int argc, char const *argv[]) {
    vector<int> q;
    int s, n;
    cin >> n >> s;
    // �������
    int x;
    for (int i=0; i<n; i++) {
        // �������
        cin >> x;
        q.push_back(x);
    }
    vector<vector<int>> best = getBest(s, q);
    // ��ȡ���Ž�

    cout << "�Ŷ����:" << endl;
    for (int i=0; i<s; i++) {
        // ������Ž�
        cout << "�� " << i << " ����: ";
        for (int j=0; j<best[i].size(); j++) {
            cout << best[i][j] << " ";
        }
        cout << endl;
    }
    cout << "���ƽ���ȴ�ʱ��: ";
    cout << getRes(best, n) << endl;
    // �������ֵ
    return 0;
}
