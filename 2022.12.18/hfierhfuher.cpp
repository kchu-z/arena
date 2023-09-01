#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a1, a2, b1, b2;
    char a3, b3, s;
    cin >> a1 >> a3 >> a2 >> s >> b1 >> b3 >> b2;

    long long a, b;

    bool sign = 1;

    if (s == '+') {
        a = a1 * b2 + a2 * b1;
        b = a2 * b2;
    } else if (s == '-') {
        a = a1 * b2 - a2 * b1;
        b = a2 * b2;

        if (a < 0) sign = 0;
        a = abs(a);
    } else if (s == '*') {
        a = a1 * b1;
        b = a2 * b2;
    } else if (s == '/') {
        a = a1 * b2;
        b = a2 * b1;
    }

    long long nod = __gcd(a, b);
    a /= nod;
    b /= nod;

    if (!sign) cout << '-';
    cout << a << '/' << b << endl;

    return 0;

}
