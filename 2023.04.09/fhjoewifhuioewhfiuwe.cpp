#include <bits/stdc++.h>
using namespace std;


bool check(int a, int b) {
    int br = 0;

    for (; a || b; a /= 10, b /= 10) {
        if (a % 10 != b % 10) br++;
    }

    return br == 1;
}


long long dp[1001][1001];
bool checked[1001][1001];

vector <int> edges[1001];

long long f(int n, int c) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    if (checked[n][c]) return dp[n][c];
    long long ans = 0;

    for (int x : edges[c]) ans += f(n - 1, x);
    return dp[n][c] = ans % 1000000007;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, c, ans = 0;
    cin >> n >> c;

    for (int i = 1; i <= c; i++) {
        for (int j = i + 1; j <= c; j++) {
            if (check(i, j)) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    for (int i = 1; i <= c; i++) {
        ans += f(n, c);
        cout << i << '\t';

        for (int x : edges[i]) cout << setw(3) << x;
        cout << endl;
    }

    cout << ans % 1000000007 << endl;
    return 0;

}

