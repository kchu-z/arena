#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> delta{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, s, br = 0, p = 0;
    cin >> m >> n;

    vector <vector <int>> v(m + 2, vector <int> (n + 2, -1));
    vector <pair <int, int>> current_cells;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s;
            v[i][j] = s;

            if (s == 0) {
                if (i == 1 || i == m || j == 1 || j == n) {
                    current_cells.push_back({i, j});
                    v[i][j] = -1;
                }
            }

            p += s;
        }
    }

    int t = 0;

    while (!current_cells.empty()) {
        vector <pair <int, int>> next_cells;
        br += current_cells.size();
        t++;

        for (pair <int, int> cell : current_cells) {
            for (pair <int, int> dir : delta) {
                int x = cell.first + dir.first;
                int y = cell.second + dir.second;

                pair <int, int> new_cell = {x, y};

                if (v[x][y] == 0) {
                    v[x][y] = -1;
                    next_cells.push_back(new_cell);
                }
            }
        }

        current_cells = next_cells;
    }

    int outer_corners = 0, inner_corners = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            //cout << setw(3) << v[i][j];
        }

        //cout << endl;
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            int top_left = v[i][j], top_right = v[i][j + 1], bottom_left = v[i + 1][j], bottom_right = v[i + 1][j + 1];

            if (top_left == -1 && bottom_right == -1) {
                if (top_right > 0 || bottom_left > 0) outer_corners++;
            }

            if (top_right == -1 && bottom_left == -1) {
                if (top_left > 0 || bottom_right > 0) outer_corners++;
            }

            if (top_left > 0 && bottom_right > 0) {
                if (top_right == -1 || bottom_left == -1) inner_corners++;
            }

            if (top_right > 0 && bottom_left > 0) {
                if (top_left == -1 || bottom_right == -1) inner_corners++;
            }
        }
    }

    cout << m * n - br << endl << p << endl << outer_corners << endl << inner_corners << endl;
    return 0;

}
