#include <bits/stdc++.h>
using namespace std;

unsigned long long a[100001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        unsigned long long ans = 0;

        for (int j = l; j <= r; j++) {
            ans ^= a[j];
        }

        cout << ans << ' ';
    }

    return 0;

}
