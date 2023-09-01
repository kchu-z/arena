#include <bits/stdc++.h>
using namespace std;

unsigned long long a[100000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n, k, br = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            unsigned long long ans = a[i];
            for (int k = i + 1; k <= j; k++) ans &= a[k];

            //if (ans >= k) cout << i << ' ' << j << ' ' << ans << endl;

            if (ans >= k) br++;
        }
    }

    cout << br << endl;
    return 0;

}

/**
10 6
8 2 14 6 8 3 4 5 7 9
*/
