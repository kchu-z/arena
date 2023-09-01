#include <bits/stdc++.h>
using namespace std;

int divisors(int n) {
    int sum = 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;

            if (i * i != n) sum += n / i;
        }
    }

    return sum;
}

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (divisors(i) >= i) {
            cout << i << ' ';
        }
    }

    return 0;

}
