#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, br = 0;
    cin >> m >> n;
    vector <pair <int, bool>> v(m + n);

    for (int i = 0; i < m + n; i++) {
        cin >> v[i].first;
        v[i].second = (i < m) ? true : false;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m + n; i++) {
        if (v[i].second) br++;
        else br--;

        if (i == m + n - 1 || v[i].first != v[i + 1].first) {
            for (int j = 0; j < br; j++) cout << v[i].first << ' ';

            br = 0;
        }
    }

    return 0;

}
