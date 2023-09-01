#include <bits/stdc++.h>
using namespace std;

vector <int> a(100);

int root(int u) { /// find the highest ancestor
    if (a[u] == u) return u;
    a[u] = root(a[u]);

    return a[u];
}

bool connected(int u, int v) {
    return a[u] == a[v];
}

void connect(int u, int v) {
    a[root(u)] = root(v);
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) a[i] = i;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        connect(u, v);
    }



    return 0;

}
