#include <bits/stdc++.h>
using namespace std;

int n, m, k, br;
int visited[3001][3001];

queue <pair <int, int>> q;

void push(pair <int, int> from, pair <int, int> to) {
    int x = to.first, y = to.second;
    if (min(x, y) <= 0 || x > n || y > m) return;

    if (visited[to.first][to.second]) return;
    visited[to.first][to.second] = visited[from.first][from.second] + 1;

    q.push({to.first, to.second});
}

void solve() {
    while (q.size()) {
        auto pos = q.front();
        q.pop();

        push(pos, {pos.first - 1, pos.second});
        push(pos, {pos.first + 1, pos.second});
        push(pos, {pos.first, pos.second - 1});
        push(pos, {pos.first, pos.second + 1});

        if (q.empty()) {
            cout << visited[pos.first][pos.second] - 1 << endl;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;

        q.push({u, v});
        visited[u][v] = 1;
    }

    solve();

    return 0;

}

