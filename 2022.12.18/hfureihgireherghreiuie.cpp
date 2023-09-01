#include <bits/stdc++.h>
using namespace std;

long long a, b, m;

long long power(long long exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long x = power(exp / 2);
        x = x * x % m;

        return x;
    }
    return a * power(exp - 1) % m;
}

int main() {

    cin >> a >> b >> m;

    a %= m;

    cout << power(b);

    return 0;

}
