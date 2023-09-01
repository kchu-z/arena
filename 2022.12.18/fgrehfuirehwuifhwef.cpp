#include <bits/stdc++.h>
using namespace std;

pair <unsigned long long, unsigned long long> add(pair <unsigned long long, unsigned long long> a, pair <unsigned long long, unsigned long long> b) {
    unsigned long long nok = a.second * b.second / __gcd(a.second, b.second);

    unsigned long long c = nok / a.second * a.first + nok / b.second * b.first;
    unsigned long long nod = __gcd(c, nok);

    c /= nod;
    nok /= nod;

    return {c, nok};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n;
    cin >> n;

    pair <unsigned long long, unsigned long long> s = {1, 1};

    for (int i = 2; i <= n; i++) s = add(s, {1, i});

    cout << s.first / s.second << ' ' << s.first % s.second << ' ' << s.second << endl;
    return 0;

}
