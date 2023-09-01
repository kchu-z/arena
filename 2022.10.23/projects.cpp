#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e = -1;
    cin >> n;
    vector <pair <pair <int, int>, int> > v(n);
    vector <bool> r(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        int left = v[i].first.first, right = v[i].first.second, idx = v[i].second;

        if (e >= left) r[i] = true;
        else if (i != n - 1 && right >= v[i + 1].first.first) r[i] = true;
        else r[i] = false;

        e = max(e, right);
    }

    for (int i = 0; i < n; i++) {
        cout << r[i] << '\n';
    }

    return 0;

}
