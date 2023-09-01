#include <bits/stdc++.h>
using namespace std;

int n, c;

bool check(int a, int b) {
    int br = 0;

    for (int p = 1; p <= 10 * max(a, b); p *= 10) {
        if ((a / p) % 10 != (b / p) % 10) br++;
    }

    return br == 1;
}

vector <int> edges[1001];
long long dp[1001][1001];
bool visited[1001][1001];

long long f(int n, int c) {
    if (n == 1) return 1;
    if (visited[n][c]) return dp[n][c];
    visited[n][c] = 1;

    long long ans = 0;
    for (int x : edges[c]) ans += f(n - 1, x);

    return dp[n][c] = ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;

    for (int i = 1; i <= c; i++) {
        for (int j = i + 1; j <= c; j++) {
            if (check(i, j)) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    long long ans = 0;

    for (int i = 1; i <= c; i++) ans += check(n, i);
    cout << ans << endl;
    return 0;

}
