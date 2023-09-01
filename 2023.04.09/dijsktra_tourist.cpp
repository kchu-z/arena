#include <bits/stdc++.h>
using namespace std;

vector <int> nodes(20001);
vector <pair <int, int>> edges[200001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[u].push_back({w, v});
        edges[v].push_back({w, u});
    }

    priority_queue <pair <int, int>> pq;

    return 0;

}
