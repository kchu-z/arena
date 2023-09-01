#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector <int> v(n), dp(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        int idx = 0;

        for (int j = i - 1; j >= 0; j--) {
            if (v[j] < v[i]) {
                idx = max(idx, dp[j]);
            }
        }

        dp[i] = idx + 1;
    }

    int mx = 0;
    for (int i = 0; i < n; i++) mx = max(mx, dp[i]);

    cout << mx << endl;
    return 0;

}
