#include <bits/stdc++.h>
using namespace std;

unsigned long long a[15], b[15];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    unsigned long long mn = c, mx = c;

    for (int i = n - 1; i >= 0; i--) {
        mn = (mn - b[i]) * a[i];
        mx = (mx - b[i] + 1) * a[i] - 1;
    }

    cout << mn << ' ' << mx << endl;
    return 0;

}
