#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, j = 0;
    cin >> n >> m;
    vector <int> v(n), s(m);

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++) cin >> s[i];

    sort(v.begin(), v.end());
    sort(s.begin(), s.end());

    for (int i : s) {
        for (j; j < n; j++) {
            if (v[j] == i) {
                j++;
                break;
            }

            cout << v[j] << ' ';
        }
    }

    for (j; j < n; j++) {
        cout << v[j] << ' ';
    }

    return 0;

}
