#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSum (vector<int> array) {
    int start = 0, l = 0, r = 0, i = 1, n = array.size();
    int temp = 0;
    int max = array[0];
    while (i < n) {
        if (array[i-1]>= 0) {
            array[i] += array[i-1];
        } else {
            start = i;
        }

        if (array[i] > max) {
            max = array[i];
                l = start;
                r = i;
        }

        i++;
    }
    vector<int> res;
    res.push_back(max);
    max -= array[r];
    res.push_back(l); res.push_back(r);
    return res;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int i = 1;
    while (i <= n) {
        int num;
        cin >> num;
        vector<int> v;
        vector<int> res;
        int temp;
        while (num--) {
            cin >> temp;
            v.push_back(temp);
        }
        res = maxSum(v);
        cout << "Case " << i  << ":" << endl;
        cout << res[0] << " " << res[1]+1 << " " << res[2]+1 << endl;
        if (i!=n) cout << endl;
        i++;
    }
}