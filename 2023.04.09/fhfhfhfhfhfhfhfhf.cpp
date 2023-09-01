#include <bits/stdc++.h>
using namespace std;

long long a[101], prefix[101], dp[101][101];
long long c[101][101];
bool visited[101][101];


/// Брой редици от първите n елемента и първа позиция на n - к
long long f(int n, int k) {
    if (n == 1) {
        if (k == 1) return 1;
        return 0;
    }
    if (k <= 0) return 0;

    if (visited[n][k]) return dp[n][k];
    visited[n][k] = 1;

    long long valid_positions = prefix[n] - k, ans = 0;
    long long combinations = c[valid_positions][a[n] - 1];

    for (int i = 1; i < k; i++) ans +=  f(n - 1, i);

    return dp[n][k] = combinations * ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 100; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
        }
    }

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];

        //cout << prefix[i] << ' ';
    }

    long long ans = 0;
    for (int i = n; i <= prefix[n]; i++) ans += f(n, i);

    cout << ans << endl;
    return 0;

}
