#include <bits/stdc++.h>
using namespace std;

unsigned long long c[101][101];

bool visited[101][101][101];
unsigned long long dp[101][101][101];

long long f(long long x, long long y, long long n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1) return x * y;
    if (x * y < n) return 0;

    if (visited[x][y][n]) return dp[x][y][n];
    visited[x][y][n] = 1;

    return dp[x][y][n] = (
        x * c[y][2] % 1000001 * f(x - 1, y - 2, n - 2) % 1000001
        + y * c[x][2] % 1000001 * f(x - 2, y - 1, n - 2) % 1000001
        + ((x * y * (x - 1) * (y - 1)) / 2) % 1000001 * f(x - 2, y - 2, n - 2) % 1000001
        + ((c[x][n] % 1000001) * c[y][n]) % 1000001) % 1000001;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 100; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    int x, y, n;
    cin >> x >> y >> n;

    cout << f(x, y, n) << endl;

    return 0;
}
