#include <bits/stdc++.h>
using namespace std;

long long nok(long long a, long long b) {
    return a * b / __gcd(a, b);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    long long lcm = nok(nok(nok(a, b), c), d), br = lcm;

    while ((br + 1) % n) br += lcm;

    cout << br + 1 << endl;
    return 0;

}

