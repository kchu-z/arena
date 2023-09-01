#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

pair <long long, long long> bezu(long long a, long long b) {
    if (b == 0) return {1, 0};

    auto p = bezu(b, a % b);
    return {p.second, p.first - p.second * (a / b)};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b, c, nod;
    cin >> a >> b >> c;
    nod = gcd(a, b);

    if (c % nod) {
        cout << "Impossible" << endl;
        return 0;
    }

    a /= nod;
    b /= nod;
    c /= nod;

    auto p = bezu(a, b);

    for (int k = -c * nod; k <= c * nod; k++) {
        long long x = p.first * c + b * k;
        long long y = p.second * c - a * k;

        if (x >= 0 && y >= 0) {
            cout << p.first * c + b * k << ' ' << p.second * c - a * k << endl;
            return 0;
        }
    }

    cout << "Impossible" << endl;
    return 0;

}
