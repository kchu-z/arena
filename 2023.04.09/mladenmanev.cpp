#include <bits/stdc++.h>
using namespace std;

vector <int> edges[100001];
int ancestor[100001], in[100001], out[100001], timer;

void dfs(int u, int _ancestor) {
    if (in[u]) return;
    ancestor[u] = _ancestor;

    timer++;
    in[u] = timer;

    for (int v : edges[u]) {
        dfs(v, u);
    }

    out[u] = timer;
}

bool subtree(int u, int v) {
    return in[u] >= in[v] && out[u] <= out[v];
}

int solve(int u, int v) {
    if (subtree(v, u)) {
        for (int w : edges[u]) {
            if (w != ancestor[u] && subtree(v, w)) return w;
        }
    }
    return ancestor[u];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }

    return 0;

}
