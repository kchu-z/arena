#include <bits/stdc++.h>
using namespace std;

int bs(int num, vector <int>& v) {
    int l = 0, r = v.size() - 1;
    int ans = v.size();

    while (l <= r) {
        int m = (l + r) / 2;

        if (v[m] >= num) {
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
        int num;
        cin >> num;
        cout << bs(num, v) << '\n';
    }

    return 0;

}
/// 9 6 2 3 3 2 5 1 6 1 1 5 1 4 10 10 9
