#include <bits/stdc++.h>
using namespace std;

string mul(string a, string b) {
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

    int n;
    cin >> n;

    string s = "1";

    for (int i = 2; i <= n; i += 3) {
        long long pr = i;
        if (i < n) pr *= i + 1;
        if (i < n - 1) pr *= i + 2;

        s = mul(s, to_string(pr));
    }

    int sum = 0;

    for (char& i : s) sum += i - '0';
    cout << sum << endl;

    return 0;

}
