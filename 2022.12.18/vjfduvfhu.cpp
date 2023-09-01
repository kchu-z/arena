#include <bits/stdc++.h>
using namespace std;

int main() {

    char s;
    long long a, b;
    cin >> a >> s >> b;

    long long whole = a / b;
    a %= b;

    long long gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;

    vector <int> v, br(10 * b);

    while (1) {
        v.push_back(10 * a / b);
        a *= 10;

        if (br[a] != 0) break;
        br[a] = v.size();
        a %= b;
    }

    int pos = br[a] - 1;
    v.pop_back();

    cout << whole;

    if (v.size() == 1 && v[0] == 0) return 0;

    cout << '.';
    for (int i = 0; i < pos; i++) cout << v[i];

    if (v.size() == pos + 1 && v[pos] == 0) return 0;

    cout << '(';
    for (int i = pos; i < v.size(); i++) cout << v[i];
    cout << ')' << endl;

    return 0;

}
