#include <bits/stdc++.h>
using namespace std;

vector <long long> getdiv(long long n) {
    vector <long long> d;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i * i != n) d.push_back(n / i);
        }
    }

    sort(d.begin(), d.end());
    return d;
}

int main() {

    long long n, a, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vector <long long> divisors = getdiv(a);

        bool f = false;

        for (int x : divisors) {
            if (x * 2 >= b * (b + 1)) {
                cout << a / x << endl;
                f = true;
                break;
            }
        }

        if (!f) cout << -1 << endl;
    }

    return 0;

}
