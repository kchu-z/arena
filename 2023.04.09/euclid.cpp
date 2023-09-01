#include <bits/stdc++.h>
using namespace std;

pair <long long, long long> bezu(long long a, long long b) {
    if (b == 0) return {1, 0};
    auto p = bezu(b, a % b);

    return {p.second, p.first - p.second * (a / b)};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;
    long long nod = __gcd(a, b);

    if (c % nod) {
        cout << "Impossible";
        return 0;
    }

    a /= nod;
    b /= nod;
    c /= nod;

    auto p = bezu(a, b);
    p.first *= c;
    p.second *= c;

    //cout << p.second / a << ' ' << (p.first - 1) / b << endl;
    //cout << a << ' ' << b << ' ' << c << endl;
    //cout << p.first << ' ' << p.second << endl;
    long long lower = ceil(-p.first * 1.0 / b);
    long long upper = floor(p.second * 1.0 / a);

    if (lower <= upper) cout << upper - lower + 1 << endl;
    else cout << "Impossible";

    return 0;

}
