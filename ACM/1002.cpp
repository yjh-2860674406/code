#include <iostream>
#include <string>

using namespace std;

string Add (string a, string b) {
    int la = a.size();
    int lb = b.size();
    int lc = la > lb ? la : lb;
    string c(lc, ' ');
    int temp , sum;
    int carry = 0;
    while (lc--) {
        int aa, bb;
        aa = la ? a[--la] - '0' : 0;
        bb = lb ? b[--lb] - '0' : 0;
        sum = bb + aa + carry;
        temp = sum % 10;
        carry = sum / 10;
        c[lc] = temp + '0';
    }
    if (carry) return '1' + c;
    return c;
}

int main(int argc, char const *argv[]) {
    string a, b;
    int c=1, n; cin >> n;
    while (c<=n) {
        cin >> a >> b;
        cout << "Case " << c << ":" << endl;
        cout << a << " + " << b << " = " << Add(a, b) << endl;
        if (c != n) cout << endl;
        c++;
    }
    return 0;
}