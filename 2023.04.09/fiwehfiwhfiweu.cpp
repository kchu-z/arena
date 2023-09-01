#include <bits/stdc++.h>
using namespace std;

int a[14][14], n, m;

int mx = 0;

int solve(int x, int y) {
    return a[x][y] + max({
        a[x - 1][y] + a[x][y - 1],
        a[x - 1][y] + a[x - 1][y - 1],
        a[x - 1][y] + a[x - 1][y + 1],
        a[x - 1][y] + a[x - 2][y],
        a[x][y - 1] + a[x][y - 2],
        a[x][y - 1] + a[x - 1][y - 1],
        a[x][y - 1] + a[x + 1][y - 1]
    });
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            a[i][j] = -10000;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i + 2][j + 2];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mx = max(mx, solve(i + 2, j + 2));
        }
    }

    cout << mx << endl;
    return 0;

}
