#include <bits/stdc++.h>
using namespace std;

int sieve[1000001];

int phi(int n) {
    int ans = n;

    while (n != 1) {
        int p = sieve[n];

        while (n % p == 0) n /= p;

        ans = ans / p * (p - 1);
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;

        for (int j = i; j <= 1000000; j += i) {
            if (sieve[j] == 0) sieve[j] = i;
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cout << phi(x) << ' ';
    }

    return 0;

}
