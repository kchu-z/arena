#include <bits/stdc++.h>
using namespace std;

int v[1001][1001], a[1000001], br = 0;

int root(int u) {
    if (a[u] == u) return u;
    return a[u] = root(a[u]);
}

void connect(int u, int v) {
    a[root(u)] = root(v);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 1000000; i++) a[i] = i;

    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j] == v[i - 1][j]) connect(v[i - 1][j], v[i][j]);
            if (v[i][j] == v[i][j - 1]) connect(v[i][j - 1], v[i][j]);
        }
    }
    unordered_map <int, bool> mp;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j]) mp[root(v[i][j])] = 1;
        }
    }
    cout << mp.size() << endl;
    return 0;

}
