#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    int br = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            br++;
            if (n != i * i) br++;
        }
    }

    return br;
}

int main() {

    int n, k, br = 0;
    cin >> n >> k;
    vector <int> d(n + 1);

    for (int i = 1; i <= n; i++) {
        d[i] = f(i);
    }

    for (int x = 1; x <= n; x++) {
        if (d[x] * k >= x) {
            int it = k * d[x] / __gcd(k * d[x], x);
            //cout << it << '\n';

            for (int y = it; y <= n; y += it) {
                if (k * d[x] * d[y] == x * y && x <= y) {
                    //cout << x << ' ' << y << '\n';
                    br++;
                }
            }
        }
    }

    cout << br << endl;
    return 0;

}
