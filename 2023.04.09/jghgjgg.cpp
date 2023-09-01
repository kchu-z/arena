#include <bits/stdc++.h>
using namespace std;

int get_distance(pair <int, int> from, pair <int, int> to) {
    auto u = from.first, v = from.second;
    auto x = to.first, y = to.second;

    x -= u;
    y -= v;

    return abs(x) + abs(y);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, mx = 0;
    cin >> n >> m >> k;

    vector <pair <int, int>> viruses;

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        viruses.push_back({u, v});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mn = INT_MAX;

            for (auto virus : viruses) {
                mn = min(mn, get_distance(virus, {i, j}));
            }

            mx = max(mx, mn);

            //cout << i << ' ' << j << ' ' << mn << endl;
        }
    }

    cout << mx << endl;
    return 0;

}
