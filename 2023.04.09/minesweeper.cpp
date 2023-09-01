#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long getPower(int n) {
    long long ans = 1;

    for (int i = 0; i < n / 60; i++) ans = (ans * (1152921504606846976 % MOD)) % MOD;
    for (int i = 0; i < n % 60; i++) ans = (ans * 2) % MOD;

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    long long ans = getPower(n);

    if (n % 3 == 2) {
        long long s = getPower((n + 1) / 3);
        ans = ((ans - s) % MOD + MOD) % MOD;
    }

    cout << ans << endl;

    return 0;

}
/// 2^60 = 1152921504606846976

