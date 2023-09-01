#include <bits/stdc++.h>
using namespace std;

int n, m, k, br, x;
vector <int> l[50001], r[50001], v(50001), visited(50001, -1);

void dfs1(int p) {
    if (visited[p] == x) return;
    visited[p] = x;

    v[p]++;
    if (v[p] == 2 * k) br++;

    for (int u : l[p]) dfs1(u);
}

void dfs2(int p) {
    if (visited[p] == x) return;
    visited[p] = x;

    v[p]++;
    if (v[p] == 2 * k) br++;

    for (int u : r[p]) dfs2(u);
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        l[u].push_back(v);
        r[v].push_back(u);
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        dfs1(a);
        x++;
        dfs2(b);
        x++;
    }

    cout << br << endl;

    for (int i = 1; i <= 50000; i++) {
        if (v[i] == 2 * k) cout << i << ' ';
    }

    return 0;

}
