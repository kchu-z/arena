#include <bits/stdc++.h>
using namespace std;

int n, mx = 0, mxn = 0;

int main() {

    cin >> n;
    vector <int> sieve(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) sieve[j]++;
    }

    for (int i = 1; i <= n; i++) {
        if (mx < sieve[i]) {
            mx = sieve[i];
            mxn = i;
        }
    }

    cout << mxn << endl << mx << endl;

    return 0;

}
