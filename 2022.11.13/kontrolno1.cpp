#include <bits/stdc++.h>
using namespace std;

/*bool isInComposition(int x, int _count) {
    x /= _count;
    return x % 2;
}

int getNumber(vector <pair <int, int>> v) {
    int n = 1;

    for (pair <int, int>& p : v) {
        for (int i = 0; i < p.second; i++) n *= p.first;
    }

    return n;
}*/

int main() {

    long long n, mn = INT_MAX, mn1, mn2;
    cin >> n;

    vector <long long> factors;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (n != i * i) factors.push_back(n / i);
        }
    }

    //sort(factors.begin(), factors.end());

    for (int i = 0; i < factors.size(); i++) {
        for (int j = i + 1; j < factors.size(); j++) {
            long long nod = __gcd(factors[i], factors[j]);
            long long nok = factors[i] * factors[j] / nod;

            if (nok == n) {
                if (max(factors[i], factors[j]) % min(factors[i], factors[j]) == 0) continue;
                if (mn > abs(factors[i] - factors[j])) {
                    mn = abs(factors[i] - factors[j]);
                    mn1 = factors[i];
                    mn2 = factors[j];
                }
            }
        }
    }

    if (mn1 > mn2) swap(mn1, mn2);
    if (mn != INT_MAX) cout << mn1 << ' ' << mn2;
    else cout << "No solution";

    return 0;

}
