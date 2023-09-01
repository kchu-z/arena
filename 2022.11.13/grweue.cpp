#include <bits/stdc++.h>
using namespace std;

int main() {

    int a, b, c, d, A, B;
    char s1, s2, g;
    cin >> a >> s1 >> b >> g >> c >> s2 >> d;

    int nod = __gcd(b, d);

    if (g == '+') cout << (a * d + b * c) / nod << '/' << b * d / nod;
    else if (g == '-') cout << (a * d - b * c) / nod << '/' << b * d / nod;
    else {
        if (g == '*') {
            A = a * c;
            B = b * d;
        } else if (g == '/') {
            A = a * d;
            B = b * c;
        }

        nod = __gcd(A, B);

        cout << A / nod << '/' << B / nod;
    }

    return 0;

}
