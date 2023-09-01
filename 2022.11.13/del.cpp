#include <bits/stdc++.h>
using namespace std;

int power(int base, int n) {
    int x = 1;
    for (int i = 0; i < n; i++) x *= base;
    return x;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, n, q;
    cin >> n >> q;
    vector <int> sieve(n + 1), counter(n + 1);
    queue <int> v;

    for (int i = 2; i <= n; i++) {
        if (sieve[i]) continue;

        for (int j = i; j <= n; j += i) {
            if (!sieve[j]) sieve[j] = i;
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        int ans = 1;

        while (a != 1) {
            if (counter[sieve[a]] == 0) v.push(sieve[a]);
            counter[sieve[a]]++;
            a /= sieve[a];
        }

        while (b != 1) {
            if (counter[sieve[b]] == 0) v.push(sieve[b]);
            counter[sieve[b]]++;
            b /= sieve[b];
        }

        while (!v.empty()) {
            int num = v.front();

            ans *= power(num, counter[num] / 2);
            counter[num] = 0;

            v.pop();
        }

        cout << ans << ' ';
    }

    return 0;

}
