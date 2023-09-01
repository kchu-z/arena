#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    if (a * b - c == a) {
        cout << a << endl;
        return 0;
    }

    while (k) {
        k--;
        a = min(d, a * b - c);

        if (a <= 0 || a == d || a * (b - 1) - c == 0) break;
    }

    cout << ((a >= 0) ? a : 0) << endl;
    return 0;

}
