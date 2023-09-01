#include <bits/stdc++.h>
using namespace std;

long long fact(long long n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long br = 0;
    string s, m;
    cin >> s >> m;

    sort(s.begin(), s.end());

    for (int i = 0; i < m.size(); i++) {
        for (int j = i + 1; j < m.size(); j++) {
            if (m[i] == m[j]) {
                cout << 0;
                return 0;
            }
        }
    }

    for (char i : m) {
        bool f = 0;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == i) {
                f = true;
                break;
            }
        }

        if (!f) {
            cout << 0;
            return 0;
        }
    }

    for (int i = 0; i <= s.size() - m.size(); i++) {
        br += fact(s.size() - m.size()) / fact(s.size() - m.size() - i) * (i + 1);
    }

    cout << br << endl;
    return 0;

}

