#include <bits/stdc++.h>
using namespace std;

long long power(int base, int exponent) {
    if (exponent == 0) return 1;
    return base * power(base, exponent - 1);
}

int main() {

    long long n = 3, mx = 0;
    vector <int> bags_cap(n), luggage(n);

    for (int i = 0; i < n; i++) cin >> bags_cap[i];
    for (int i = 0; i < n; i++) cin >> luggage[i];

    //sort(bags_cap.begin(), bags_cap.end());
    //sort(luggage.begin(), luggage.end());

    for (int i = 0; i < power(n, n); i++) {
        long long cmp = i, br = 0;
        vector <int> bags(n);

        for (int j = 0; j < n; j++) {
            int bag = cmp % n;
            bags[bag] += luggage[j];

            if (bags[bag] <= bags_cap[bag]) br++;
            cmp /= n;
        }

        mx = max(mx, br);
    }

    cout << mx << endl;
    return 0;

}
