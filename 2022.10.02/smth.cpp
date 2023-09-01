#include <bits/stdc++.h>
using namespace std;

long long d(long long n, long long j) {
    long long x = 0;
    if (j == 1) j++;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            x = i;
            while (n % i == 0) {n /= i;}
        }
    }

    if (n != 1) x = max(x, n);
    return x;
}

int f(long long n) {
    cout << n << '\t';
    long long p = d(n, 1);

    while (1) {
        n += p;
        if (d(n, p) != p) {
            cout << n << '\n';
            return 0;
        }
    }

    return 0;
}

int main() {

    for (int i = 2; i < 1000; i++) f(i);

    return 0;

}
