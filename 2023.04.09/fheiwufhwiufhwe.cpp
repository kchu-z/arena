#include <bits/stdc++.h>
using namespace std;

long long fact(long long n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}

int main() {

    long long n;
    cin >> n;

    for (long long x = 1; x <= n; x++) {
    cout << sqrt(fact(n) / x) << ' ' << cbrt(fact(n) / x) << endl;
    }
    return 0;

}
