#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> delta{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char s;
    int m, n;
    cin >> m >> n;

    vector <vector <bool>> v(m + 2, vector <bool> (n + 2));
    vector <pair <int, int>> current_cells;

    pair <int, int> finish_cell;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s;

            if (s == '#' || s == 'S') v[i][j] = 0;
            else v[i][j] = 1;

            if (s == 'S') current_cells.push_back({i, j});
            if (s == 'F') finish_cell = {i, j};
        }
    }

    int t = 0;

    while (!current_cells.empty()) {
        t++;
        vector <pair <int, int>> next_cells;

        for (pair <int, int> cell : current_cells) {
            for (pair <int, int> dir : delta) {
                int x = cell.first + dir.first;
                int y = cell.second + dir.second;

                pair <int, int> new_cell = {x, y};

                if (v[x][y]) {
                    v[x][y] = 0;
                    next_cells.push_back(new_cell);

                    if (finish_cell == new_cell) {
                        cout << t << endl;
                        return 0;
                    }
                }
            }
        }

        current_cells = next_cells;
    }

    return 0;

}
