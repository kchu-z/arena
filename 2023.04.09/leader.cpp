#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mx = INT_MIN;
    cin >> n;
    vector <int> v(n), s;

    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = n - 1; i >= 0; i--) {
        if (v[i] >= mx) {
            mx = v[i];
            s.push_back(v[i]);
        }

    }

    reverse(s.begin(), s.end());
    for (int x : s) cout << x << ' ';
    return 0;

}
