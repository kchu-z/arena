#include <bits/stdc++.h>
using namespace std;

unsigned long long bitmask[64];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n, total_xor = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        unsigned long long x;
        cin >> x;

        total_xor ^= x;

        for (int p = 0; p < 64; p++) {
            if ((x & (1 << p)) != 0) bitmask[p] ^= x;
        }
    }

    unsigned long long first = 0;

    for (int p = 0; p < 64; p++) {
        if (bitmask[p] != total_xor && bitmask[p] != 0) {
            first = bitmask[p];
            //break;
        }
    }

    unsigned long long second = total_xor ^ first;

    cout << min(first, second) << ' ' << max(first, second) << endl;
    return 0;

}
/**
10 14 7 21 9 14 17 17 7 19 9
*/
