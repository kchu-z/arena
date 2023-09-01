#include <bits/stdc++.h>
using namespace std;

long long c[101][101];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 100; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
        }
    }

    long long n, a, b, ans = 0;
    cin >> n >> a >> b;
    n -= 5;
    a -= 3;
    b -= 2;

    for (long long boys = 0; boys <= min(n, a); boys++) {
        long long girls = n - boys;
        if (girls > b) continue;

        ans += c[a + 3][boys + 3] * c[b + 2][girls + 2];
    }

    cout << ans << endl;
    return 0;

}
