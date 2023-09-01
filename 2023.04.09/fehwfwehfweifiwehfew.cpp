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

    long long nod = __gcd(a, b);
    a /= nod;
    b /= nod;

    if (c % nod) {
        cout << "No solution!";
        return 0;
    }

    c /= nod;

    auto p = bezu(a, b);
    cout << c * p.first << ' ' << c * p.second << endl;

    return 0;

}
