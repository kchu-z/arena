#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mx = 0;
    cin >> n;
    vector <pair <int, int>> v(n);

    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    if (v[1].first <= v[0].second) cout << "1\n";
    else cout << "0\n";

    mx = v[0].second;

    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1].first <= v[i].second || v[i].first <= mx) cout << '1';
        else cout << '0';
        cout << '\n';

        mx = max(mx, v[i].second);
    }

    if (v[n - 1].first <= mx) cout << "1\n";
    else cout << "0\n";

    return 0;

}
