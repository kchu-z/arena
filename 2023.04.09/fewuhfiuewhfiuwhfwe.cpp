#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int dp[100001];
bool check[100001];

int f(int k) {
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (k < a) return 0;
    if (k == a) return 1;

    if (check[k]) return dp[k];
    check[k] = true;

    long long ans = (long long) f(k - a) + (long long) f(k - 1) - (long long) f(k - b - 1);
    ans %= 1000000007;
    if (ans < 0) ans += 1000000007;

    return dp[k] = ans;
}

int main() {

    cin >> n >> a >> b;

    if (a != 1) dp[1] = 0;
    else dp[1] = 1;

    long long ans = 0;

    for (int s = a; s <= b; s++) ans += f(b + 1 - s);
    dp[b + 1] = ans % 1000000007;

    cout << f(n) << endl;

    //for (int i = 1; i <= n; i++) cout << i << '\t' << dp[i] << '\n';

    return 0;

}
