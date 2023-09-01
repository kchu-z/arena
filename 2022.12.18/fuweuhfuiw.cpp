#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("game.11.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, a = 0, b = 0;
    cin >> n;
    vector <vector <int>> v(n, vector <int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) sort(v[i].begin(), v[i].end());

    for (int br = 0; br < n * n; br++) {
        int min_max_idx = 0;

        for (int i = 1; i < n; i++) {
            if (!v[i].empty()) {
                if (v[min_max_idx].back() > v[i].back()) min_max_idx = i;
            }
        }

        if (br % 2 == 0) b += v[min_max_idx].back();
        else a += v[min_max_idx].back();

        v[min_max_idx].pop_back();
    }

    cout << a << ' ' << b;
    return 0;

}
