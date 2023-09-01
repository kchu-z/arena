#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
long long c[301][301], dp[301][301];
bool check[301][301];

long long n, m, k;


long long f(long long n, long long m) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (m == 0) return 0;

    if (check[n][m]) return dp[n][m];
    check[n][m] = 1;

    long long ans = 0;

    for (int i = 0; i <= min(n, k); i++) {
        ans += (c[n][i] * f(n - i, m - 1)) % MOD;
    }

    return dp[n][m] = ans % MOD;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i <= 300; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }

    cout << f(n, m);
    return 0;

}
