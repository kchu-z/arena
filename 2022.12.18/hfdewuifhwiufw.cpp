#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> v;


int bs(int l, int r, pair <int, int> p) {
    int m = (l + r) / 2;

    if (p == v[m]) return m;
    if (p < v[m]) return bs(l, m - 1, p);
    if (p > v[m]) return bs(m + 1, r, p);
}

pair <int, int> get(int idx) {
    int l = 0, r = 0;

    if (idx != 0 && v[idx].first == v[idx - 1].first) l = v[idx - 1].second + 1;
    if (idx + 1 != v.size() && v[idx].first == v[idx + 1].first) r = v[idx + 1].second + 1;

    return {l, r};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back({a[i], i});
    }

    sort(v.begin(), v.end());

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int idx;
        cin >> idx;
        idx--;

        pair <int, int> p = {a[idx], idx}, s = get(bs(0, v.size() - 1, p));
        cout << s.first << ' ' << s.second << '\n';
    }

    return 0;

}

/*

8 2 4 5 4 4 2 7 4 3 1 8 4

*/
