#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10];
int dp[100000];

bool visited[100000];

int f(int n) {
    if (n < 0) return INT_MIN;
    if (n == 0) return 0;

    if (visited[n]) return dp[n];
    visited[n] = 1;

    int ans = INT_MIN;

    for (int i = 0; i < k; i++) ans = max(ans, 1 + f(n - a[i]));

    return dp[n] = ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }


    cout << max(f(n), -1);
    return 0;

}
