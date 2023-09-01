#include <bits/stdc++.h>
using namespace std;

int comp[101][101], a[10001], br = 0;

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

    for (int i = 0; i <= 10000; i++) a[i] = i;

    int m, n, k;
    cin >> m >> n >> k;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            comp[i][j] = (i - 1) * n + j;
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        comp[x][y] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (comp[i][j]) {
                if (comp[i - 1][j]) connect(comp[i - 1][j], comp[i][j]);
                if (comp[i][j - 1]) connect(comp[i][j - 1], comp[i][j]);
            }
        }
    }

    unordered_map <int, bool> mp;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (comp[i][j]) mp[root(comp[i][j])] = 1;
        }
    }

    cout << mp.size() << endl;
    return 0;

}
