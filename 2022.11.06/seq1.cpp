#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, br = 0, mx = 0, c = 0;
    cin >> n;
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        br++;
        if (i == n - 1 || v[i] != v[i + 1]) {
            mx = max(mx, br);
            br = 0;
        }

        if (i < n - 3 && v[i] + v[i + 1] + v[i + 2] + v[i + 3] == 15) c++;
    }

    cout << mx << ' ' << c;

    return 0;

}
