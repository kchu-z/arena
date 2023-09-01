#include <bits/stdc++.h>
using namespace std;

pair <int, int> d[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {

    long long n, m, rot = 0;
    cin >> n >> m;
    int arr[n + 2][m + 2], check[n + 2][m + 2];

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            check[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            check[i][j] = false;
        }
    }

    int x = 0, y = 0;

    while (1) {
        cout << arr[pos.first][pos.second] << ' ';
        check[pos.first][pos.second] = true;

        if (check[pos.first + 1][pos.second] && check[pos.first - 1][pos.second] && check[pos.first][pos.second + 1] && check[pos.first][pos.second - 1]) break;
        while (check[pos.first + d[rot].first][pos.second + d[rot].second]) rot = (rot + 1) % 4;

        pos = {pos.first + d[rot].first, pos.second + d[rot].second};
    }

    return 0;

}
