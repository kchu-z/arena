#include <bits/stdc++.h>
using namespace std;

int n, m, k, br = 0;

pair <int, int> trans(pair <int, int> p) {
    return {min(p.first, n - p.first - 1), min(p.second, m - p.second - 1)};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    vector <pair <int, int>> ivo;

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        ivo.push_back(trans({u, v}));
    }

    sort(ivo.begin(), ivo.end());

    for (int i = 0; i < k; i++) {
        if (i + 1 == k || ivo[i] != ivo[i + 1]) {
            auto p = ivo[i];

            if (p.first * 2 + 1 == n) {
                if (p.second * 2 + 1 == m) {
                    br++;
                } else {
                    br += 2;
                }
            } else {
                if (p.second * 2 + 1 == m) {
                    br += 2;
                } else {
                    br += 4;
                }
            }
        }
    }

    cout << br << endl;
    return 0;

}
