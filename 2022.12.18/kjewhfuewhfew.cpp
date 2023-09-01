#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, mx = 0;
    cin >> n;
    vector <long long> v, s;

    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;

        v.push_back(x - y);
        mx = max(mx, y);
    }

    long long nod = v[0];

    for (int i = 1; i < n; i++) {
        nod = __gcd(nod, v[i]);
    }

    if (mx == 0) s.push_back(1);
    if (nod != 1) s.push_back(nod);

    for (int i = 2; i * i <= nod; i++) {
        if (nod % i == 0) {
            if (nod / i > mx)s.push_back(nod / i);
            if (i * i != nod && i > mx) s.push_back(i);
        }
    }

    cout << s.size() << endl;
    sort(s.begin(), s.end());
    for (long long x : s) cout << x << ' ';

    cout << endl;
    return 0;

}
