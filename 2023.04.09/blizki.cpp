#include <bits/stdc++.h>
using namespace std;

vector <int> edges[1001];

bool is_close(int a, int b) {
    int br = 0;

    for (int p = 1; p <= 10 * max(a, b); p *= 10) {
        if ((a / p) % 10 != (b / p) % 10) br++;
    }

    return br == 1;
}

long long dp[1001][1001];
bool check[1001][1001];

const long long MOD = 1000000007;

long long f(int n, int c) {
    if (n == 1) return 1;
    if (check[n][c]) return dp[n][c];
    check[n][c] = 1;

    long long ans = 0;

    for (int x : edges[c]) {
        ans += f(n - 1, x);
    }

    return dp[n][c] = ans % MOD;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;

    long long ans = 0;

    for (int i = 1; i <= c; i++) {
        for(int j = i + 1; j <= c; j++) {
            if (is_close(i, j)) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    for (int i = 1; i <= c; i++) {
        ans += f(n, i);
    }

    cout << ans % MOD << endl;
    return 0;

}
