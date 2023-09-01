#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector <int> a;

int root(int u) {
    if (a[u] == u) return u;
    a[u] = root(a[u]);
    return a[u];
}

void connect(int u, int v) {
    a[root(u)] = root(v);
}

bool check(int u, int v) {
    return root(u) == root(v);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    a.resize(n + 1);

    for (int i = 1; i < n; i++) a[i] = i;

    set <pair <int, int>> st;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        st.insert({min(u, v), max(u, v)});
    }

    cin >> q;

    vector <pair <int, pair <int, int>>> qna;
    vector <bool> ans;

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        qna.push_back({a, {b, c}});

        if (a == 2) {
            st.erase({min(b, c), max(b, c)});
        }
    }

    for (auto p : st) {
        connect(p.first, p.second);
    }

    reverse(qna.begin(), qna.end());

    for (auto p : qna) {
        if (p.first == 1) ans.push_back(check(p.second.first, p.second.second));
        else if (p.first == 2) connect(p.second.first, p.second.second);
    }

    reverse(ans.begin(), ans.end());

    for (bool i : ans) cout << i;

    return 0;

}
