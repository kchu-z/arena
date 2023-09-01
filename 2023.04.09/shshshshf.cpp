#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        auto x = power(base, exp / 2);
        return x * x;
    }

    return base * power(base, exp - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, p;
    cin >> n >> p;

    vector <int> powers;

    for (long long i = 1; i < n; i *= p) {
        powers.push_back(i);
    }

    long long bound = power(2, powers.size());

    for (long long x = 0; x < bound; x++) {
        long long num = 0;

        for (int i = 0; i < powers.size(); i++) {
            if (x & (1 << i) != 0) num += powers[i];
        }

        cout << num << '\n';
    }

    return 0;

}
