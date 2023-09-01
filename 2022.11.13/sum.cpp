#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a, b, p, q;
    cin >> a >> b >> p >> q;
    long long nok = p * q / __gcd(p, q);

    long long newA = a + nok - ((a - 1) % nok + 1);
    long long newB = b - (b % nok);

    newA /= nok;
    newB /= nok;

    long long sum = newB * (newB + 1) / 2 - newA * (newA - 1) / 2;
    sum *= nok;

    ///cout << nok << ' ' << newA << ' ' << newB << ' ';
    cout << sum;

    return 0;

}
