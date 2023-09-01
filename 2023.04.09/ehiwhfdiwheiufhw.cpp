#include <bits/stdc++.h>
using namespace std;

long long dp[101][10001];
bool can_pass[101][10001], check[101][10001];
int n, m;

long long f(int x, int y) {
    if (x == 0 || n < x) return 0;
    if (!can_pass[x][y]) return 0;

    if (x == 1 && y == 1) return 1;
    if (y == 1) return 0;

    if (check[x][y]) return dp[x][y];
    check[x][y] = 1;

    return dp[x][y] = (f(x - 1, y - 1) + f(x, y - 1) + f(x + 1, y - 1)) % 1000000007;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char s;
            cin >> s;

            can_pass[i][j] = (s == '.');
            //cout << can_pass[n][m] << ' ';
        }
        //cout << endl;
    }

    cout << f(n, m) << endl;
    return 0;

}

/**

3 6
......
..#...
.#.#..

*/
