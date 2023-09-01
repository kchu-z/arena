#include <bits/stdc++.h>
using namespace std;

long long dp[1000001], a[1000001], mx = INT_MIN;

long long f(long long n) {
    if (n < 0) return 0;
    mx = max(mx, dp[n] = a[n] + max((long long) 0, f(n - 1)));

    return dp[n];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    f(n - 1);

    cout << mx << endl;
    return 0;

}
