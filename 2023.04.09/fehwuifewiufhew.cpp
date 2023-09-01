#include <bits/stdc++.h>
using namespace std;

pair <long long, long long> bezu(long long a, long long b) {
    if (b == 0) return {1, 0};
    auto p = bezu(b, a % b);

    return {p.second, p.first - p.second * (a / b)};
}

int main() {

    long long a, b, c;
    cin >> a >> b >> c;

    long long gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;

    if (c % gcd) {
        cout << "no" << endl;
        return 0;
    }

    c /= gcd;

    auto p = bezu(a, b);
    p.first *= c;
    p.second *= c;

    if (p.first == 0 || b == 0) {
        cout << p.first * gcd << ' ' << p.second * gcd << endl;
    } else if (p.first < 0) {
        if (-(p.first % b) <= p.first % b + b) cout << p.first % b * gcd << ' ' << (p.second + a * (p.first / b)) * gcd << endl;
        else cout << (p.first % b + b) * gcd << ' ' << (p.second + a * (p.first / b + 1)) * gcd << endl;
    } else if (p.first > 0) {
        if (p.first % b <= -(p.first % b - b)) cout << p.first % b * gcd << ' ' << (p.second + a * (p.first / b)) * gcd << endl;
        else cout << (p.first % b + b) * gcd << ' ' << (p.second + a * (p.first / b + 1)) * gcd << endl;
    }

    return 0;

}
