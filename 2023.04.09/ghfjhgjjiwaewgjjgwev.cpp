#include <bits/stdc++.h>
using namespace std;

long long n, m, p, q;
bool visited[10001][2];
long long dp[10001][2];

int f(long long m, bool eat) {
    if (eat && m + p >= n) return 1;
    if (m >= n) return 1;

    if (visited[m][eat]) return dp[m][eat];
    visited[m][eat] = 1;

    if (eat) return dp[m][eat] = (f(m + p, 0) + f(m + p, 1));
    return f(m - q, 1);
}

int main() {

    cin >> m >> n >> p >> q;

    cout << f(m, 1);
    return 0;

}
