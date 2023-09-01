#include <iostream>
#include <queue>
using namespace std;

bool visited[1000][1000];
bool is_patient[1000][1000];
int ttime[1000][1000];
int patients[1000][1000];
int n, m;
queue <pair <int, int>> q;

/**void push(int x, int y, int u, int v) {

    if (min(x, y) < 0 || x >= n || y >= m) return;
    cout << u << ' ' << v << ' ' << ' ' << ' ' << x << ' ' << y << '\n';

    if (visited[x][y]) {
        //if (patients[u][v].first + 1 == patients[x][y].first) {
        //    patients[x][y] = {patients[x][y].first, max(patients[u][v].second + is_patient[x][y], patients[x][y].second)};
        //}

        return;
    }

    visited[x][y] = 1;
    patients[x][y] = {patients[u][v].first + 1, patients[u][v].second + is_patient[x][y]};
    q.push({x, y});
}*/

void push(int x, int y, int u, int v) {

    if (min(x, y) < 0 || x >= n || y >= m) return;
    ///cout << u << ' ' << v << ' ' << ' ' << ' ' << x << ' ' << y << '\n';

    int tm = ttime[u][v] + 1;
    int pt = patients[u][v] + is_patient[u][v];

    if (visited[x][y]) {
        if (tm == ttime[x][y]) {
            patients[x][y] = max(patients[x][y], pt);
        }

        return;
    }

    visited[x][y] = 1;
    ttime[x][y] = tm;
    patients[x][y] = pt;

    q.push({x, y});
}

int main() {

    cin >> n >> m;

    pair <int, int> end_square;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == 'x') visited[i][j] = 1;
            else if (c == 'S') {
                visited[i][j] = 1;
                q.push({i, j});
            } else if (c == 'T') {
                end_square = {i, j};
            } else if (c == '+') is_patient[i][j] = 1;

        }
    }

    while (!q.empty()) {
        auto pos = q.front();

        push(pos.first - 1, pos.second, pos.first, pos.second);
        push(pos.first + 1, pos.second, pos.first, pos.second);
        push(pos.first, pos.second - 1, pos.first, pos.second);
        push(pos.first, pos.second + 1, pos.first, pos.second);

        q.pop();
    }

    /**for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << time[i][j] << ' ';
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << patients[i][j] << ' ';
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << ' ';
        }

        cout << endl;
    }

    cout << endl;*/



    cout << ttime[end_square.first][end_square.second] << ' ';
    cout << patients[end_square.first][end_square.second] << '\n';
    return 0;

}
