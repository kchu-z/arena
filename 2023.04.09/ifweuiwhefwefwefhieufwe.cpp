#include <bits/stdc++.h>
using namespace std;

int n, m;

bool is_door[100][100];
bool is_block[100][100];

int t1[100][100];
int t2[100][100];
int t3[100][100];

bool v1[100][100];
bool v2[100][100];
bool v3[100][100];

vector <pair <int, int>> people;
deque <pair <int, int>> exits, p1, p2;

void push1(pair <int, int> from, pair <int, int> to) {
    int u = from.first, w = from.second;
    int x = to.first, y = to.second;

    if (min(x, y) < 0 || x >= n || y >= m) return;

    if (v1[x][y] || is_block[x][y]) return;
    v1[x][y] = 1;

    if (is_door[x][y]) {
        t1[x][y] = t1[u][w] + is_door[x][y];
        p1.push_back({x, y});
    } else {
        t1[x][y] = t1[u][w];
        p1.push_front({x, y});
    }
}

void push2(pair <int, int> from, pair <int, int> to) {
    int u = from.first, w = from.second;
    int x = to.first, y = to.second;

    if (min(x, y) < 0 || x >= n || y >= m) return;

    if (v2[x][y] || is_block[x][y]) return;
    v2[x][y] = 1;

    if (is_door[x][y]) {
        t2[x][y] = t2[u][w] + is_door[x][y];
        p2.push_back({x, y});
    } else {
        t2[x][y] = t2[u][w];
        p2.push_front({x, y});
    }
}

void push3(pair <int, int> from, pair <int, int> to) {
    int u = from.first, w = from.second;
    int x = to.first, y = to.second;

    if (min(x, y) < 0 || x >= n || y >= m) return;

    if (v3[x][y] || is_block[x][y]) return;
    v3[x][y] = 1;

    if (is_door[x][y]) {
        t3[x][y] = t3[u][w] + is_door[x][y];
        exits.push_back({x, y});
    } else {
        t3[x][y] = t3[u][w];
        exits.push_front({x, y});
    }
}

void solve() {

    while (!exits.empty()) {
        auto pos = exits.front();
        int x = pos.first, y = pos.second;

        exits.pop_front();

        push3(pos, {x - 1, y});
        push3(pos, {x + 1, y});
        push3(pos, {x, y - 1});
        push3(pos, {x, y + 1});
    }

    p1.push_back(people[0]);
    p2.push_back(people[1]);

    auto fp = people.front(), bp = people.back();
    v1[fp.first][fp.second] = 1;
    v2[bp.first][bp.second] = 1;

    while (!p1.empty()) {
        auto pos = p1.front();
        int x = pos.first, y = pos.second;

        p1.pop_front();

        push1(pos, {x - 1, y});
        push1(pos, {x + 1, y});
        push1(pos, {x, y - 1});
        push1(pos, {x, y + 1});
    }

    while (!p2.empty()) {
        auto pos = p2.front();
        int x = pos.first, y = pos.second;

        p2.pop_front();

        push2(pos, {x - 1, y});
        push2(pos, {x + 1, y});
        push2(pos, {x, y - 1});
        push2(pos, {x, y + 1});
    }


    int ans = t3[fp.first][fp.second] + t3[bp.first][bp.second];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v1[i][j] && v2[i][j] && v3[i][j]) {
                ans = min(ans, t1[i][j] + t2[i][j] + t3[i][j] - 2 * is_door[i][j]);
            }
        }
    }

    cout << ans << endl;
    people.clear();
    exits.clear();
    p1.clear();
    p2.clear();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int queries;
    cin >> queries;

    for (int query = 0; query < queries; query++) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t1[i][j] = 0;
                t2[i][j] = 0;
                t3[i][j] = 0;
                v1[i][j] = 0;
                v2[i][j] = 0;
                v3[i][j] = 0;

                is_door[i][j] = 0;
                is_block[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;

                if (c == '#') is_door[i][j] = 1;
                else if (c == '*') is_block[i][j] = 1;
                else if (c == '$') people.push_back({i, j});

                if (c != '*' && (i == 0 || j == 0 || i + 1 == n || j + 1 == m)) {
                    exits.push_back({i, j});
                    v3[i][j] = 1;

                    if (c == '#') t3[i][j] = 1;
                }
            }
        }

        solve();

    }

    return 0;

}
