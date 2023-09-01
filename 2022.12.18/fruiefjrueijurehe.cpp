#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, mn = INT_MAX, x = 0, y = 0;
    cin >> n;
    vector <long long> v;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (n != i * i) v.push_back(n / i);
        }
    }

    sort(v.begin(), v.end());



    for (int i = 0; i < v.size(); i++) {
        long long a = v[i];
        for (int j = i + 1; j < v.size(); j++) {
            long long b = v[j];

            if (a * b / __gcd(a, b) == n) {
                if (b - a < mn) {
                    x = a;
                    y = b;

                    mn = b - a;
                }
            }
        }
    }

    if (v.empty() || x == 0 || y == 0) {
        cout << "No solution" << endl;
        return 0;
    }

    cout << x << ' ' << y << endl;
    return 0;

}
