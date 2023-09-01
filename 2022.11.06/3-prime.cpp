#include <bits/stdc++.h>
using namespace std;

int getNumber(vector <pair <int, int>> prime_factors) {
    int num = 1;

    for (auto& p : prime_factors) {
        for (int i = 0; i < p.second; i++) num *= p.first;
    }

    return num;
}

int getPower(int num, int _maxpow, int _count) {
    num /= _count;
    num %= 2 * _maxpow;

    if (num >= _maxpow) num = _maxpow - (num - _maxpow) - 1;
    return num;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, maxdiv = 1;
    cin >> n;

    vector <pair <int, int>> prime_factors;

    for (int i = 2; i * i <= n; i++) {
        int br = 0;

        while (n % i == 0) {
            br++;
            n /= i;
        }

        if (br != 0) prime_factors.push_back({i, br});
        maxdiv *= br + 1;
    }

    if (n != 1) {
        prime_factors.push_back({n, 1});
        maxdiv *= 2;
    }

    /*int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        prime_factors.push_back({a, b});
        maxdiv *= b + 1;
    }*/

    for (int i = 0; i < maxdiv; i++) {
        vector <pair <int, int>> num;

        int br = 1;

        for (pair <int, int> p : prime_factors) {
            num.push_back({p.first, getPower(i, p.second + 1, br)});
            br *= p.second + 1;
        }

        cout << getNumber(num) << ' ';
    }

    return 0;

}
