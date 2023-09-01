#include <iostream>
using namespace std;

long long dp[21][31];
bool visited[21][31];
long long n, m, s;

long long f(long long n, long long s) {
    if (s <= 0) return 0;
    if (n == 0) return 1;

    if (visited[n][s]) return dp[n][s];
    visited[n][s] = 1;

    long long ans = 0;

    for (int k = 0; k < m; k++) {
        ans += f(n - 1, s - k);
    }

    return dp[n][s] = ans;
}

int main() {

    cin >> m >> n >> s;

    cout << f(n, s);
    return 0;

}
