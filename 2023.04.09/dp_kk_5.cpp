#include <bits/stdc++.h>
using namespace std;

unsigned long long n, m, k, dp[1001][1001];
bool check[1001][1001];

unsigned long long f(int len, int p) {
    if (len == 0) return 1;
    if ((m - p) * k < len) return 0;
    if ((m - p) * k == len) return 1;

    if (check[len][p]) return dp[len][p];
    check[len][p] = 1;

    for (int i = 0; i <= min(len, (int) k); i++) {
        dp[len][p] += f(len - i, p + 1);
    }

    return dp[len][p];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    cout << f(n, 0);
    return 0;

}
