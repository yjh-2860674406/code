#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    while (n) {
        int num = n;
        map<string, int> m;
        string str;
        while (num--) {
            cin >> str;
            if (m.count(str)) {
                m.find(str)->second++;
            } else {
                m.insert(pair<string, int>(str, 0));
            }
        }
        int max = 0;
        map<string, int>::iterator iter = m.begin();
        while (iter != m.end()) {
            if (iter->second > max) max = iter->second;
            iter++;
        }
        iter = m.begin();
        while (iter != m.end()) {
            if (iter->second == max) cout << iter->first << endl;
            iter++;
        }
        cin >> n;
    }
    return 0;
}
