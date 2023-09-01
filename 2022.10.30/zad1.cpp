#include <bits/stdc++.h>
using namespace std;

long long v[1000001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, x, y, br = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        long long g = __gcd(x, y);
        long long b = x * y / g / g;
        v[g] += b;
    }

    for (int i = 0; i < 1000000; i++) {
        if (v[i] != 0) cout << i << ' ' << v[i] << '\n';
    }

    return 0;

}
