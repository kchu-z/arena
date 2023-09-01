#include <bits/stdc++.h>
using namespace std;

int dp[501][125001];
bool check[501][125001];

int mod(long long n) {
    n %= 1000000007;
    if (n < 0) n += 1000000007;

    return n;
}

int f(int n, int k) {
    if (k < 0) return 0;
    if (n * (n - 1) / 2 < k) return 0;

    if (n == 1) {
        if (k == 0) return 1;
        return 0;
    }

    if (k == 0) return 1;

    if (check[n][k]) return dp[n][k];
    check[n][k] = true;

    return dp[n][k] = mod((long long) f(n - 1, k) + (long long) f(n, k - 1) -  (long long) f(n - 1, k - n));

}

int main() {

    int n, k;
    cin >> n >> k;

    cout << f(n, k) << endl;
    return 0;

}
