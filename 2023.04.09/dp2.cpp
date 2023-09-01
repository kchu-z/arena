#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001];

long long f(long long n, long long k) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    k = min(n, k);
    if (k == 1) return 1;

    if (dp[n][k]) return dp[n][k];

    long long ans = 0;

    for (int i = 1; i <= k; i++) {
        ans += f(n - i, i);
        ans %= 1000000007;
    }

    return dp[n][k] = ans;
}

int main() {

    long long n;
    cin >> n;

    cout << f(n, n) << endl;
    return 0;

}
