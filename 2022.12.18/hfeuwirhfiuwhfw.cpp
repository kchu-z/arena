#include <bits/stdc++.h>
using namespace std;

long long n, p;
string chars = "abcdefghijklmnopqrstuvwxyz";

long long power(long long base, long long exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long x = power(base, exp / 2);
        return x * x;
    }

    return base * power(base, exp - 1);
}

void solve() {
    if (p > power(2, n) - 1) {
        cout << 0 << endl;
        exit(0);
    }

    if (p % 2 == 1) {
        cout << chars[n - 1] << endl;
        exit(0);
    }

    n--;
    p /= 2;

    solve();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;

    solve();
    return 0;

}
