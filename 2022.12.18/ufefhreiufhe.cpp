#include <bits/stdc++.h>
using namespace std;

long long power(int n) {
    if (n == 0) return 1;
    return 2 * power(n - 1);
}

int main() {

    int n;
    cin >> n;
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    long long p = power(n);

    for (long long i = 0; i < p; i++) {
        long long k = i, s = 0;
        vector <bool> v2(n);

        for (int j = 0; j < n; j++) {
            if (k % 2) s += v[j];
            else s -= v[j];

            v2[j] = k % 2;
            k /= 2;
        }

        if (s == 0) {
            for (bool i : v2) cout << i << ' ';
            cout << endl;
        }
    }

    return 0;

}
