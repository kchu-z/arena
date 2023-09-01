#include <bits/stdc++.h>
using namespace std;

long long c[21][21];

int c1[256], c2[256];

int main() {

    long long ans = 0, stringsize;

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

    for (int ss = 0; ss <= stringsize; ss++) {
        long long current = 1;
        for (int i = 0; i < 256; i++) {
            if (c2[i]);
            ans *= c[ss][min(s, c2[i]]);
            ss -= min(s, c2[i]);
        }
    }

    cout << ans << endl;
    return 0;

}
