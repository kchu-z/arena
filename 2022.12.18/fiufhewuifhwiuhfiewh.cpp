#include <bits/stdc++.h>
using namespace std;

void solve(long long n) {
    long long p = 1;
    if ((n / 10) % 2) p = 9;

    if (n % 10 >= 3) p *= 3;
    if (n % 10 >= 7) p *= 7;
    if (n % 10 >= 9) p *= 9;

    cout << p % 10 << endl;
}

int main() {

    long long k, l, m;
    cin >> k >> l >> m;

    solve(k);
    solve(l);
    solve(m);

    return 0;

}
