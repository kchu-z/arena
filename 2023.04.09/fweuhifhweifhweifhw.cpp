#include <bits/stdc++.h>
using namespace std;

long long a[100001], dp[100001];

long long f(int n) {
    if (n <= 0) return 0;
    if (dp[n]) return dp[n];

    return dp[n] = max({f(n - 1), f(n - 2) + a[n], f(n - 3) + a[n] + a[n - 1]});
}

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << f(n) << endl;
    return 0;

}
