#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a, b, c, d, t;
    cin >> a >> b >> c >> t >> d;

    long long nok = a * b * c / (__gcd(__gcd(a, b), __gcd(b, c)));


    return 0;

}
