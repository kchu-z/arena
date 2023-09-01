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

    vector <vector <int>> v(m + 2, vector <int> (n + 2, -1));
    vector <pair <int, int>> current_cells;

    pair <int, int> start_cell, finish_cell;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s;

            if (s == 'X' || s == '*' || s == 'S') v[i][j] = -1;
            else v[i][j] = 500;

            if (s == '*') current_cells.push_back({i, j});
            if (s == 'S') start_cell = {i, j};
            if (s == 'D') finish_cell = {i, j};
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

                if (v[x][y] == 500 && new_cell != finish_cell) {
                    v[x][y] = t;
                    next_cells.push_back(new_cell);

                    if (finish_cell == new_cell) {
                        //cout << t << endl;
                        //return 0;
                    }
                }
            }
        }

        current_cells = next_cells;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            //cout << setw(3) << v[i][j];
        }

        //cout << endl;
    }

    t = 0;
    current_cells = {start_cell};

    while (!current_cells.empty()) {
        t++;
        vector <pair <int, int>> next_cells;

        for (pair <int, int> cell : current_cells) {
            for (pair <int, int> dir : delta) {
                int x = cell.first + dir.first;
                int y = cell.second + dir.second;

                pair <int, int> new_cell = {x, y};

                if (t < v[x][y]) {
                    v[x][y] = -1;
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

    cout << "Impossible\n";
    return 0;

}
