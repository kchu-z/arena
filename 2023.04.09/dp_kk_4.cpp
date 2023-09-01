#include <bits/stdc++.h>
using namespace std;

int N, M, K;

unsigned long long c[1001][1001], dp[1001][1001];
bool check[1001][1001];

unsigned long long f(int n, int m) {
    if (n == 0) return 1;
    if (m == M) return 0;

    if (check[n][m]) return dp[n][m];
    check[n][m] = true;

    unsigned long long ans = 0;
    for (int i = 0; i <= min(K, n); i++) ans += c[n][i] * f(n - i, m + 1);

    return dp[n][m] = ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    c[0][0] = 1;

    for (int i = 1; i <= 1000; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    cout << f(N, 1);

    return 0;

}
