#include <bits/stdc++.h>
using namespace std;

long long p[50000][500], dp[50000][500];
bool visited[50000][500];

long long f(long long n, long long m, long long M) {
    if (n == 0) return 0;

    if (visited[n][m]) return dp[n][m];
    visited[n][m] = 1;

    long long ans = LLONG_MAX;

    for (long long k = 0; k < M; k++) {
        ans = min(ans, max(f(n - 1, k, M), abs(p[n][m] - p[n - 1][k])));
    }

    return dp[n][m] = ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> p[i][j];
        }
    }

    long long ans = LLONG_MAX;

    for (long long M = 0; M < m; M++) {
        ans = min(ans, f(n - 1, M, m));
    }

    cout << ans << endl;
    return 0;

}

