#include <bits/std++.h>
using namespace std;

long long a[1001];
long long dp[1001][1001];
bool visited[1001][1001];

long long n, k;

long long f(long long n, long long s) {
    if ((s - n) % k == 0) return 0;

    return f(a[n], ((s - n) % k + k) % k);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= k;
    }

    for (int i = 1; i <= n; i++) {
        cout << f(i, 0) << ' ';
    }

    c
    return 0;

}
