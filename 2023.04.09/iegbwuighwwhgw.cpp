#include <bits/stdc++.h>
using namespace std;

int bitmask[64][2];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    n = 3 * n + 1;

    for (int i = 0; i < n; i++) {
        unsigned long long x;
        cin >> x;

        for (int p = 0; p < 64; p++) {
            if ((x >> p) == 0) break;

            //cout << ((x >> p) & 1);
            bitmask[p][(x >> p) & 1]++;
        }

        //cout << endl;
    }

    unsigned long long ans = 0;

    for (int i = 0; i < 64; i++) {
        int current = 0;
        if (bitmask[i][1] % 3) current = 1;

        ans += (1 << i) * current;
    }

    cout << ans << endl;
    return 0;

}
