#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, x, y;
bool is_block[2000][2000];
int l[2000][2000];

deque <pair <int, int>> q;

void push(pair <int, int> from, pair <int, int> to) {
    auto [u, v] = from;
    auto [x, y] = to;
//    int u = from.first, v = from.second;
//    int x = to.first, y = to.second;

    if (min(x, y) < 0 || x >= n || y >= m || is_block[x][y]) return;
    pair <int, int> delta = {x - u, y - v};

    int tm = l[u][v];
    bool added = false;

    if (delta.first == 0 && delta.second == -1) {
        tm++;
        added = true;
    }

    if (tm < l[x][y] || !l[x][y]) {
        l[x][y] = tm;

        if (added) q.push_back(to);
        else q.push_front(to);
    }
}

void solve() {

    q.push_back({r, c});
    l[r][c] = 1;

    while (q.size()) {
        auto pos = q.front();
        q.pop_front();

        push(pos, {pos.first - 1, pos.second});
        push(pos, {pos.first + 1, pos.second});
        push(pos, {pos.first, pos.second - 1});
        push(pos, {pos.first, pos.second + 1});
    }



}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int br = 0;

    cin >> n >> m >> r >> c >> x >> y;
    r--;
    c--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == '*') is_block[i][j] = 1;
        }
    }

    solve();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (is_block[i][j]) continue;
            int L = l[i][j] - 1;
            int R = j + L - c;

            if (L <= x && R <= y) br++;
            //cout << (L <= x && R <= y && !is_block[i][j]) << ' ';
        }

        //cout << endl;
    }

    cout << br << endl;
    return 0;

}
