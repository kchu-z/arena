#include <bits/stdc++.h>
using namespace std;

int a[100001], c[100001], mnc[100001], cost;
vector <int> edges[100001];

int root(int u) {
    if (a[u] == u) return u;
    return a[u] = root(a[u]);
}

void connect(int u, int v) {
    if (root(u) == root(v)) return;

    cost += abs(mnc[root(u)] - mnc[root(v)]);
    a[root(u)] = root(v);
    mnc[root(u)] = min(mnc[root(u)], mnc[root(v)]);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        mnc[i] = c[i];
    }

    for (int i = 0; i < n; i++) {
        int u, v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cout << cost;
    return 0;

}
