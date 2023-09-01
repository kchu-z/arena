#include <bits/stdc++.h>
using namespace std;

int v[60000002];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, d = 0, mn = 60000002, mx = 0, num, val;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> num;
        val = 30000000 + num - k * i;
        v[val]++;
        mn = min(val, mn);
        mx = max(val, mx);
    }

    for (int i = mn; i <= mx; i++) {
        d = max(d, v[i]);
    }

    cout << n - d;

    return 0;

}
