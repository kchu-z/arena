#include <bits/stdc++.h>
using namespace std;

int p;
long long dp[31][31];
bool check[31][31];

long long f(int n, int s) {
    if (!n) return 1;

    if (check[n][s]) return dp[n][s];
    check[n][s] = true;

    for (int i = 0; i < min(s, p); i++) dp[n][s] += f(n - 1, s - i);
    return dp[n][s];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> p >> n >> s;

    cout << f(n, s) << endl;
    return 0;

}
