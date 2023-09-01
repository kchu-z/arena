#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, br = 0;
    cin >> n >> q;
    vector <pair <int, int>> v;
    vector <int> ans(q);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        v.push_back({a, -1});
        v.push_back({b, q});
    }

    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        v.push_back({num, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == -1) br++;
        else if (v[i].second == q) br--;
        else ans[v[i].second] = br;

        //cout << v[i].first << ' ' << br << endl;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << ' ';

    return 0;

}
/// 3 4 2 5 3 7 5 10 4 11 5 8
