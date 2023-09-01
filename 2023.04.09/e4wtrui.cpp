#include <bits/stdc++.h>
using namespace std;

int ans;

int bs(vector <int>& v, int l, int r) {
    if (l > r) return -1;
    int m = (l + r) / 2;

    if (ans > v[m]) return max(m, bs(v, m + 1, r));
    return bs(v, l, m - 1);
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
        cin >> ans;
        cout << bs(v, 0, n - 1) + 1 << '\n';
    }

    return 0;

}
