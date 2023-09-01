#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

pair <long long, long long> bezu(long long a, long long b) {
    if (b == 0) return {1, 0};

    auto p = bezu(b, a % b);
    cout << p.first << ' ' << p.second << endl;

    return {p.second, p.first - p.second * (a / b)};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b, m, nod;
    cin >> a >> b >> m;
    nod = gcd(a, m);
    //cout << nod << endl;
    if (b % nod) {
        cout << "No solution" << endl;
        return 0;
    }

    auto p = bezu(a, m);
    long long v = p.first, u = p.second;
    //cout << v << ' ' << u << endl;
    long long x = ((b * v / nod) % m + m) % m;

    for (long long k = 0; k < nod; k++) {
        cout << x + k * m << endl;
    }

    return 0;

}

