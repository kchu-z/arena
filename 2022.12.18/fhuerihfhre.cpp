#include <bits/stdc++.h>
using namespace std;

long long arr[1001][1001], prefix[1001][1001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <bool> sieve(1000001, 1);
    sieve[1] = 0;

    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) {
            for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 0;
        }
    }

    int m, n, br = 0;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int x1 = 1; x1 <= m; x1++) {
        for (int x2 = x1; x2 <= m; x2++) {
            for (int y1 = 1; y1 <= n; y1++) {
                for (int y2 = y1; y2 <= n; y2++) {
                    long long pr = prefix[x2][y2] + prefix[x1 - 1][y1 - 1] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1];
                    if (sieve[pr]) br++;
                }
            }
        }
    }

    cout << br << endl;
    return 0;

}
