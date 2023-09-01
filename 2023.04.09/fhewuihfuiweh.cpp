#include <bits/stdc++.h>
using namespace std;

unsigned long long c[21][21];

int c1[256], c2[256];

long long fact(long long n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {

    unsigned long long ans = 0, stringsize;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 20; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    string s, p;
    cin >> s >> p;

    stringsize = s.size() - p.size();

    for (int i = 0; i < s.size(); i++) {
        c1[s[i]]++;
    }

    for (int i = 0; i < p.size(); i++) {
        c2[p[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (c1[s[i]] < c2[s[i]]) {
            cout << 0;
            return 0;
        }
    }

    for (int i = 0; i <= stringsize; i++) {
        ans += (i + 1) * c[stringsize][i] * fact(i);
    }

    cout << ans << endl;
    return 0;

}

