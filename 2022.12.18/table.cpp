#include <bits/stdc++.h>
using namespace std;

pair <int, int> delta[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;

    vector <vector <int>> arr(m + 2, vector <int> (n + 2));
    vector <vector <bool>> check(m + 2, vector <bool> (n + 2, true));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            check[i][j] = false;
        }
    }

    int x = 1, y = 1, dir = 0;

    while (1) {
        cout << arr[x][y] << ' ';

        if (check[x + delta[dir].first][y + delta[dir].second]) dir = (dir + 1) % 4;
        if (check[x + delta[dir].first][y + delta[dir].second]) break;
        check[x][y] = true;

        x += delta[dir].first;
        y += delta[dir].second;
    }

    return 0;

}
