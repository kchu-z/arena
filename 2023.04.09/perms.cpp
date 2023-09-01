#include <bits/stdc++.h>
using namespace std;

long long dp[501][125001];
bool check[501][125001];

long long MOD = 1000000007;

long long f(long long n, long long k) {
    if (k < 0 || n * (n - 1) < 2 * k) return 0;
    if (k == 0) return 1;
    if (n == 0) return 0;

    if (check[n][k]) return dp[n][k];
    check[n][k] = 1;

    return dp[n][k] = (MOD + f(n - 1, k) + f(n, k - 1) - f(n - 1, k - n)) % MOD;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin >> n >> k;

    cout << f(n, k) << endl;
    return 0;

}
