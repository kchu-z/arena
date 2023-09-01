#include <bits/stdc++.h>
using namespace std;

long long n, m, num, sum;

long long power(long long base, long long exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long x = power(base, exp / 2);
        return x * x % m;
    }

    return base * power(base, exp - 1) % m;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (long long exp = 2; exp <= n + 1; exp++) {
        cin >> num;
        num %= m;

        sum += power(num, exp);
        sum %= m;
    }

    cout << sum << endl;
    return 0;

}
