#include <bits/stdc++.h>
using namespace std;
long long dp[21][41][41];
bool visited[21][41][41];
long long f(int k, int x, int y) {
    if (k == 0) return (x == 0 && y == 0);
    if (visited[k][x + 20][y + 20]) return dp[k][x + 20][y + 20];
    visited[k][x + 20][y + 20] = 1;
    return dp[k][x + 20][y + 20] = f(k - 1, x - 1, y) + f(k - 1, x + 1, y) + f(k - 1, x, y - 1) + f(k - 1, x, y + 1);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, x, y;
    cin >> k >> x >> y;
    cout << f(k, x, y);
    return 0;
}
