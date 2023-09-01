#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, mx = 0;
    cin >> n;

    vector <vector <long long>> arr(n + 1, vector <long long> (n + 1));
    vector <vector <long long>> prefix(n + 1, vector <long long> (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
        }
    }

    for (long long x1 = 1; x1 <= n; x1++) {
        for (long long x2 = x1; x2 <= n; x2++) {
            for (long long y1 = 1; y1 <= n; y1++) {
                for (long long y2 = y1; y2 <= n; y2++) {
                    long long sum = prefix[x2][y2] + prefix[x1 - 1][y1 - 1] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2];

                    if (sum == 0) mx = max(mx, (x2 - x1 + 1) * (y2 - y1 + 1));
                }
            }
        }
    }

    cout << mx << endl;
    return 0;

}
