#include <bits/stdc++.h>
using namespace std;
vector <bool> sieve(10000001);
vector <int> primes;

void solve(int n) {
    for (int x : primes) {
        if (n <= x) exit(0);

        if (!sieve[n - x]) {
            cout << x << ' ' << n - x << endl;
            exit(0);
        }
    }

    exit(0);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve[0] = 1;
    sieve[1] = 1;

    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);

        for (int j = 2 * i; j <= 10000000; j += i) sieve[j] = 1;
    }

    int n;
    cin >> n;

    if (!sieve[n]) {
        cout << 1 << endl << n << endl;
        return 0;
    }

    if (n % 2 == 0) {
        cout << 2 << endl;
        solve(n);
    }

    if (!sieve[n - 2]) {
        cout << 2 << endl << 2 << ' ' << n - 2 << endl;
        return 0;
    }

    cout << 3 << endl << 3 << ' ';
    solve(n - 3);

    return 0;

}
