#include <bits/stdc++.h>
using namespace std;

bool check[101], dp[100][101];
int a, b, v[100];

int f(int n, int sum) {
    if (b < sum) return 0;

    if (n < 0) {
        if (a <= sum && !check[sum]) {
            check[sum] = 1;
            return 1;
        }

        return 0;
    }

    if (dp[n][sum]) return 0;
    dp[n][sum] = 1;

    return f(n - 1, sum) + f(n - 1, sum + v[n]);
}

int main() {

    int n;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n);

    cout << f(n - 1, 0) << endl;
    return 0;

}
