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

    vector <vector <int>> arr(m + 2, vector <int> (n + 2, -1));
    vector <vector <bool>> v(m + 2, vector <bool> (n + 2));
    vector <pair <int, int>> current_cells;

    vector <vector <int>> patients(m + 2, vector <int> (n + 2, 0));
    vector <vector <bool>> isPatient(m + 2, vector <bool> (n + 2));

    pair <int, int> finish_cell;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s;
            if (s == '+') isPatient[i][j] = 1;

            if (s == 'x' || s == 'S') v[i][j] = 0;
            else v[i][j] = 1;

            if (s == 'S') {
                current_cells.push_back({i, j});
                arr[i][j] = 0;
            }

            if (s == 'T') finish_cell = {i, j};
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

                if (!v[x][y]) continue;
                if (arr[x][y] != -1 && arr[x][y] != t) continue;

                if (arr[x][y] == t) {
                    patients[x][y] = max(patients[x][y], patients[cell.first][cell.second] + isPatient[x][y]);
                    continue;
                }

                patients[x][y] = patients[cell.first][cell.second] + isPatient[x][y];
                next_cells.push_back(new_cell);
                arr[x][y] = t;

                //if (finish_cell == new_cell) cout << t << endl;
            }
        }

        current_cells = next_cells;
    }

    cout << arr[finish_cell.first][finish_cell.second] << ' ' << patients[finish_cell.first][finish_cell.second] << endl;

    /*for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(2) << patients[i][j];
        }

        cout << endl;
    }*/

    return 0;

}
