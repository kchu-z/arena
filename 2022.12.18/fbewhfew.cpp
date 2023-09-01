#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector <pair <int, int>> delta{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int m, n;
    cin >> m >> n;
    char c;

    vector <vector <bool>> v(m + 2, vector <bool> (n + 2));
    vector <pair <int, int>> current_cells;

    pair <int, int> finish_cell;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;

            if (c != '#') v[i][j] = 1;
            if (c == 'S') current_cells.push_back({i, j});
            if (c == 'F') finish_cell = {i, j};
        }
    }

    int t = 0;

    while (!current_cells.empty()) {
        vector <pair <int, int>> next_cells;
        t++;

        for (auto cell : current_cells) {
            for (auto dir : delta) {
                pair <int, int> new_cell = {cell.first + dir.first, cell.second + dir.second};

                if (v[new_cell.first][new_cell.second]) {
                    v[new_cell.first][new_cell.second] = 0;
                    next_cells.push_back(new_cell);

                    if (new_cell == finish_cell) cout << t << endl;
                }
            }
        }

        current_cells = next_cells;
    }

    return 0;

}
