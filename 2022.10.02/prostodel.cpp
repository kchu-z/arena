#include <bits/stdc++.h>
using namespace std;

long long d(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) n /= i;
        if (n == 1) return i;
    }

    return n;
}

bool simple(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {

    long long n;
    cin >> n;
    long long p = d(n);
    long long m = n / p;

    if (d(n + p) > p) {
        cout << n + p;
        return 0;
    }

    if (d(n + 2 * p) > p) {
        cout << n + 2 * p;
        return 0;
    }

    if (m <= p) {
        m = p;
    }

    while (1) {
        m++;
        if (simple(m)) {
            cout << m * p << endl;
            return 0;
        }
    }


    return 0;

}
