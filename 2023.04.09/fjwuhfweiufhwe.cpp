#include <bits/stdc++.h>
using namespace std;

long long c[41][41];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, br = 0;
    cin >> n;

    for (int i = 0; i <= 40; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    vector <pair <long long, int>> primes;

    if (n % 2 == 0) primes.push_back({2, 0});

    while (n % 2 == 0) {
        n /= 2;
        primes.back() = {primes.back().first, primes.back().second + 1};
    }

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) primes.push_back({i, 0});

        while (n % i == 0) {
            n /= i;
            primes.back() = {primes.back().first, primes.back().second + 1};
        }
    }

    if (n != 1) primes.push_back({n, 1});

    for (auto p : primes) br += p.second;

    long long ans = 1;

    for (auto p : primes) {
        ans *= c[br][p.second];
        br -= p.second;
    }

    cout << ans << endl;
    return 0;

}
