#include <bits/stdc++.h>
using namespace std;

long long dp[51][51];
bool check[51][51];

long long f(long long n, long long k) {
    if (n == 1) return k;
    if (k < 1) return 0;
    if (check[n][k]) return dp[n][k];
    check[n][k] = 1;

    long long ans = 0;

    for (int i = 1; i <= k; i++) {
        ans += f(n - 1, i - 1);
    }

    return dp[n][k] = ans;
}

int main() {

    long long n, r;
    cin >> r >> n;

    cout << f(n, r);
    return 0;

}
