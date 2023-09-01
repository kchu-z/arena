#include <bits/stdc++.h>
using namespace std;

vector <int> edges[100001];
int visited[100001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int k;
    cin >> k;

    queue <int> q;

    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;

        q.push(u);
        visited[u] = 1;
        //cout << u << '\n';
    }

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : edges[u]) {
            if (visited[v]) continue;

            q.push(v);
            visited[v] = visited[u] + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << visited[i] - 1 << '\n';
    }

    return 0;

}
/**
6 7
1 2 1 3 1 6 2 3 3 4 4 5 5 6
2
1 3
*/
