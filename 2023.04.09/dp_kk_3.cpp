#include <bits/stdc++.h>
using namespace std;



unsigned long long dp[1001][1001];

unsigned long long f(int n, int k) {
    if (n <= 0) return 1;
    if (k == 1) return 1;
    if (dp[n][k]) return dp[n][k];

    unsigned long long ans = 0;
    for (int m = 1; m <= k; m++) ans += f(n - 1, m);

    return dp[n][k] = ans;
}

int main() {

    int n, m;
    cin >> n >> m;

    cout << f(n, m);

    return 0;

}
