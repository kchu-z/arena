#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, mn = INT_MAX;
    cin >> n;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (__gcd(i, n / i) != 1) continue;
            mn = min(mn, i + n / i);
        }
    }

    cout << mn << endl;

    return 0;

}
