#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;

    for (int _ = 0; _ < m; _++) {

        int n;
        cin >> n;

        unordered_map <int, int> ac, bc;
        vector <int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i].first;
            ac[v[i].first]++;
        }

        for (int i = 0; i < n; i++) {
            cin >> v[i].second;
            bc[v[i].second]++;
        }

    }

    return 0;

}
