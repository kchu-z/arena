#include <bits/stdc++.h>
using namespace std;

long long a[100000], c[51][51];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 50; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
        }
    }

    int n, m, k;
    cin >> n >> m >> k;

    int c2 = 0, c4 = (n / 2) * (m / 2);


    if (k % 2 == 1 && (n % 2 == 0 || m % 2 == 0)) {
        cout << 0 << endl;
        return 0;
    }

    if (k % 2 == 1) k--;

    if (n % 2 == 0) {
        if (m % 2 == 0) {

        } else {
            c2 += n / 2;
        }
    } else {
        if (m % 2 == 0) {
            c2 += m / 2;
        } else {
            c2 += (n / 2) + (m / 2);
        }
    }

    long long ans = 0;

    for (int i = 0; i <= c2; i++) {
        if ((k - 2 * i) % 4 == 0) {
            ans += c[c2][i] * c[c4][(k - 2 * i) / 4];
        }
    }

    cout << ans << endl;
    return 0;

}

