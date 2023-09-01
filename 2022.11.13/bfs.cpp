#include <bits/stdc++.h>
using namespace std;

int bs1(int x, vector <int>& v) {
    int l = 0, r = v.size() - 1;
    int ans = v.size();

    while (l <= r) {
        int m = (l + r) / 2;

        if (x <= v[m]) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    return ans;
}

int bs2(int x, vector <int>& v) {
    int l = 0, r = v.size() - 1;
    int ans = v.size();

    while (l <= r) {
        int m = (l + r) / 2;

        if (x < v[m]) {
            ans = m;
            r = m - 1;

        } else l = m + 1;
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        int idx1 = bs1(x, v), idx2 = bs2(x, v);
        ///cout << idx1 << ' ' << idx2 << endl;
        cout << idx1 << ' ' << idx2 - idx1 << ' ' << v.size() - idx2 << '\n';
    }


    return 0;

}
/// 5 2 1 4 3 3 2 3 5
