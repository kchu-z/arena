#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k, prev, br = 0, ans = 0;
    cin >> n >> k >> prev;
    br++;

    cout << br;

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;

        if ((bool) (x >= k) != (bool) (prev >= k)) {
            if (prev >= k) ans += br * (br + 1) / 2;
            prev = x;
            br = 0;
        }

        br++;
        //cout << ' ' << br;

        if (i + 1 == n && x >= k) {
            ans += br * (br + 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;

}
