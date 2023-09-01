#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    char s;

    vector <long long> plus_sign(n + 1), minus_sign(n + 1), v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> s;
        v[i] = v[i - 1];

        if (s == '+') {
            plus_sign[i] = plus_sign[i - 1] + 1;
            minus_sign[i] = minus_sign[i - 1];
        } else {
            plus_sign[i] = plus_sign[i - 1];
            minus_sign[i] = minus_sign[i - 1] + 1;

            v[i] += plus_sign[i];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << v[r] - v[l - 1] - plus_sign[l - 1] * (minus_sign[r] - minus_sign[l - 1]) << '\n';
    }

    return 0;

}
