#include <bits/stdc++.h>
using namespace std;

int main() {

    int k1, m1, c1;
    int k2, m2, c2;
    int k3, m3, c3;
    cin >> k1 >> m1 >> c1;
    cin >> k2 >> m2 >> c2;
    cin >> k3 >> m3 >> c3;

    m1 += k1 * 1000;
    c1 += m1 * 100;

    m2 += k2 * 1000;
    c2 += m2 * 100;

    m3 += k3 * 1000;
    c3 += m3 * 100;

    int c = c1 + max(c2, c3);

    cout << c / 100000 << ' ' << c / 100 % 1000 << ' ' << c % 100 << endl;
    return 0;

}
