#include <bits/stdc++.h>
using namespace std;

int dp[32], n, p;

int pow(int exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        auto x = pow(exp / 2);
        return x * x;
    }
    return p * pow(exp - 1);
}

int f(int k, int lim) {
    if (lim < 0) return 0;

    if (k == 1) {
        if (lim == 0) return 1;
        if (lim >= 1) return 2;
    }

    return pow(k) + f(k - 1, lim - pow(k));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    cout << (int) (log(n) / log(p)) + 1 << endl;

    cout << f((int) (log(n) / log(p)), n) - 1 << endl;
    return 0;

}
