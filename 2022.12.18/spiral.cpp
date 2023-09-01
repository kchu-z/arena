#include <bits/stdc++.h>
using namespace std;

pair <int, int> delta[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int arr[102][102];
bool check[102][102];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n + 2; i++) {
        check[0][i] = 1;
        check[n + 1][i] = 1;
        check[i][0] = 1;
        check[i][n + 1] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    int x = 1, y = 1, dir = 0;

    while (1) {
        cout << arr[x][y] << ' ';

        if (check[x + delta[dir].first][y + delta[dir].second]) dir = (dir + 1) % 4;
        if (check[x + delta[dir].first][y + delta[dir].second]) break;

        x += delta[dir].first;
        y += delta[dir].second;
    }

    return 0;

}
