#include <bits/stdc++.h>
using namespace std;

long long a[1001];
long long dp[1001][1001];
bool visited[1001][1001];

long long n, k;

long long f(long long n, long long s) {
    if ((s - n) % k == 0) return 1;
    //cout << n << ' ' << s << endl;

    if (visited[n][s]) return dp[n][s];
    visited[n][s] = 1;

    //cout << n << ' ' << s << ' ' << f(a[n], ((s - n) % k + k) % k) << '\n';
    //cout << n << ' ' << s << ' ' << a[n] << ' ' << ((s - n) % k + k) % k << '\n';

    return dp[n][s] = 1 + f(a[n], ((s - n) % k + k) % k);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    for (int p = 1; p <= n; p++) {
        long long ans = f(a[p], 0);

        cout << max(ans, (long long) 0) << ' ';
    }

    return 0;

}
