#include <bits/stdc++.h>
using namespace std;

string mul(string& a, string& b) {
    if (a == "0" || b == "0") return "0";

    vector <int> m;
    vector <int> n;
    vector <int> res(a.size() + b.size() + 1);

    for (int i = 0; i < a.size(); i++) m.push_back(a[i] - '0');
    for (int i = 0; i < b.size(); i++) n.push_back(b[i] - '0');

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < n.size(); j++) {
            res[i + j] += m[i] * n[j];
        }
    }

    for (int i = 0; i < a.size() + b.size(); i++) {
        int pr = res[i] / 10;
        res[i] %= 10;
        res[i + 1] += pr;
    }

    string N;

    for (int i : res) {
        N.push_back(i + '0');
    }

    while (N.back() == '0') N.pop_back();

    return N;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string x;
    long long n;
    cin >> x >> n;
    string str = "1";

    if (x == "1" || n == 1) {
        cout << 1;
        return 0;
    }

    reverse(x.begin(), x.end());

    while (n - (int) str.size() > 0) {
        n -= (int) str.size();
        str = mul(str, x);
    }

    cout << str[str.size() - n] << endl;

    return 0;

}
