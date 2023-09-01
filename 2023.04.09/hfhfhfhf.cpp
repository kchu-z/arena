#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[101][101], visited2[101][101];
bool is_block[101][101], is_block2[101][101];

queue <pair <int, int>> q;

void push1(pair <int, int> from, pair <int, int> to) {
    int x = to.first, y = to.second;
    if (min(x, y) < 0 || x >= n || y >= m) return;
    //cout << x << ' ' << y << endl;
    if (visited[to.first][to.second]) return;
    //cout << x << ' ' << y << endl;
    visited[x][y] = visited[from.first][from.second] + 1;

    if (!is_block[x][y]) q.push({to.first, to.second});
}

void solve1() {
    //cout << q.size() << endl;
    while (q.size()) {
        auto pos = q.front();
        q.pop();

        push1(pos, {pos.first - 1, pos.second});
        push1(pos, {pos.first + 1, pos.second});
        push1(pos, {pos.first, pos.second - 1});
        push1(pos, {pos.first, pos.second + 1});
    }

    /**for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            is_block[i][j] = 0;
            visited[i][j] = 0;
        }
    }*/
}

void push2(pair <int, int> from, pair <int, int> to) {
    int x = to.first, y = to.second;
    if (min(x, y) < 0 || x >= n || y >= m) return;
    //cout << x << ' ' << y << endl;
    if (visited2[to.first][to.second]) return;
    //cout << x << ' ' << y << endl;
    visited2[x][y] = visited2[from.first][from.second] + 1;

    if (!is_block2[x][y]) q.push({to.first, to.second});
}

void solve2() {
    //cout << q.size() << endl;
    while (q.size()) {
        auto pos = q.front();
        q.pop();

        push2(pos, {pos.first - 1, pos.second});
        push2(pos, {pos.first + 1, pos.second});
        push2(pos, {pos.first, pos.second - 1});
        push2(pos, {pos.first, pos.second + 1});
    }

    /**for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            is_block[i][j] = 0;
            visited[i][j] = 0;
        }
    }*/
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    pair <int, int> end_pos;
    int mn = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == '#') {
                is_block[i][j] = 1;
                is_block2[i][j] = 1;
            }
            else if (c == 'E') end_pos = {i, j};
            else if (c == 'B') {
                q.push({i, j});
                visited[i][j] = 1;

                //cout << visited[i][j] << endl;
            }
        }
    }

    solve1();
    q.push(end_pos);
    visited2[end_pos.first][end_pos.second] = 1;
    solve2();


    /**for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] - 1 << '\t' ;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited2[i][j] - 1 << '\t' ;
        }
        cout << endl;
    }

    cout << endl;*/

    if (visited[end_pos.first][end_pos.second]) mn = visited[end_pos.first][end_pos.second] - 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (is_block[i][j] && visited[i][j] && visited2[i][j]) {
                mn = min(mn, visited[i][j] + visited2[i][j]);
            }
        }
    }

    if (mn == INT_MAX) cout << -1;
    else cout << mn;
    return 0;

}

