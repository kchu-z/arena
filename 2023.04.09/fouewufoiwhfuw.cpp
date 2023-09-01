#include <bits/stdc++.h>
using namespace std;

long long power(int k) {
    if (k == 0) return 1;
    if (k % 2 == 0) {
        long long x = power(k / 2);
        return x * x;
    }

    return 10 * power(k - 1);
}

int main() {

    long long k;
    cin >> k;

    long long lowerBound = ceil(sqrt(power(k - 1)) / 11);
    long long upperBound = floor(sqrt(power(k) - 1) / 11);

    cout << upperBound - lowerBound + 1 << endl;
    return 0;

}
