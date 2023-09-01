#include <bits/stdc++.h>
using namespace std;

int a[100001];
int n, m, next_num = 1;

int get_next() {
    next_num++;
    return next_num - 1;
}

int root(int u) {
    if (a[u] == u) return u;
    return a[u] = root(a[u]);
}

void connect(int u, int v) {
    if (root(u) == root(v)) return;
    n--;

    a[root(u)] = root(v);
}

int main() {

    for (int i = 1; i <= 100000; i++) a[i] = i;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    unordered_map <int, int> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a = (v[a] == 0) ? (v[a] = get_next()) : v[a];
        b = (v[b] == 0) ? (v[b] = get_next()) : v[b];

        connect(a, b);
    }

    cout << n << endl;
    return 0;

}
