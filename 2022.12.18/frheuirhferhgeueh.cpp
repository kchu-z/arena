#include <bits/stdc++.h>
using namespace std;

pair <int, int> delta[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long m, n, k;
    cin >> m >> n >> k;

    vector <int> v;
    vector <vector <int>> a(m + 2, vector <int> (n + 2));
    vector <vector <bool>> arr(m + 2, vector <bool> (n + 2));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            arr[i][j] = 1;
        }
    }

    pair <int, int> cell{1, 1};
    arr[1][1] = 0;
    int dir = 0;
    v.push_back(a[cell.first][cell.second]);

    while (arr[cell.first + delta[dir].first][cell.second + delta[dir].second]) {
        pair <int, int> new_cell = {cell.first + delta[dir].first, cell.second + delta[dir].second};
        arr[new_cell.first][new_cell.second] = 0;

        if (!arr[new_cell.first + delta[dir].first][new_cell.second + delta[dir].second]) dir++;

        v.push_back(a[new_cell.first][new_cell.second]);
    }

    for (int i : v) cout << i << ' ';

    return 0;

}
