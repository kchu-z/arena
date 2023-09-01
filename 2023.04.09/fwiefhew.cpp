#include <bits/stdc++.h>
using namespace std;

unsigned long long a1, a2, b1, b2, x;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a1 >> a2 >> b1 >> b2 >> x;

    unsigned long long l = 1, r = x / min(a1, b1), ans;

    while (l <= r) {
        unsigned long long m = (l + r) / 2;

        if (x <= a1 * (m - m / a2) + b1 * (m - m / b2)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << ans << endl;
    return 0;

}
