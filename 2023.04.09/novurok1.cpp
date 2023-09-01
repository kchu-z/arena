#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mx = 0;
    cin >> n;

    vector <pair <int, int> > v(n + 1), lines;

    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    v[n] = {INT_MAX, INT_MAX};
    sort(v.begin(), v.end());

    int a = v[0].first, b = v[0].second;

    for (int i = 1; i <= n; i++) {
        if (b < v[i].first) {
            lines.push_back({a, b});
            mx = max(mx, b - a);
            a = v[i].first;
            b = v[i].second;
        } else {
            b = max(v[i].second, b);
        }
    }

    //for (auto x : lines) cout << x.first << ' ' << x.second << endl;

    cout << lines.size() << ' ' << mx << endl;

    return 0;

}
