#include <bits/stdc++.h>
using namespace std;

int n, m, c, k;
vector <int> edges[100001];
int visited[100001];

vector <int> periphery;

queue <int> q;

void push(int from, int to) {
    if (visited[to]) return;
    visited[to] = visited[from] + 1;

    if (visited[to] - 1 > k) periphery.push_back(to);

    q.push(to);
}

void solve() {
    q.push(c);
    visited[c] = 1;

    while (q.size()) {
        auto pos = q.front();
        q.pop();

        push(pos)
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m >> c >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    solve();
    sort(periphery.begin(), periphery.end());

    cout << periphery.size() << '\n';
    for (int x : periphery) cout << x << '\n';

    return 0;

}
