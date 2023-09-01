#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, br = 0, mx = 0;
    cin >> n;
    vector <long long> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    vector <bool> sieve(mx);

    for (long long i = 1; i * i <= mx; i++) {
        for (long long j = i; i * i + j * j <= mx; j++) {
            sieve[i * i + j * j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        long long num = v[i];
        if (sieve[num]) br++;
    }

    cout << br << endl;

    return 0;

}
