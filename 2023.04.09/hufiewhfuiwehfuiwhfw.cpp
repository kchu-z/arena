#include <bits/stdc++.h>
using namespace std;

unsigned long long prefix[100000], a[100000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n, q, ans;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 1; i <= q; i++) {
        unsigned long long x, l, r;
        cin >> l >> r >> x;

        ans = prefix[r] - prefix[l - 1];

        for (int j = 1; j <= x; j++) {
            unsigned long long y;
            cin >> y;

            //ans -= a[y];
            //ans += a[y] * a[y];
        }

        cout << ans << endl;
    }

    return 0;

}

/**
5 4
1 2 3 4 5
2 4 0
2 4 1 3
2 4 3 2 3 4
1 5 2 1 4
*/
