#include <bits/stdc++.h>
using namespace std;

long long a[100], dp[100][10001];
bool check[100][10001];

long long f(long long pos, long long s) {
    if (s < 0) return INT_MAX;
    if (s == 0) return 0;

    if (pos == 0) return s;

    if (check[pos][s]) return dp[pos][s];
    check[pos][s] = true;

    long long ans = INT_MAX;

    for (long long k = 0; k <= s / a[pos]; k++) {
        ans = min(ans, f(pos - 1, s - k * a[pos]) + k);
    }

    return dp[pos][s] = ans;
}

int main() {

    long long s, n;
    cin >> s >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    cout << f(n - 1, s) << endl;
    return 0;

}
