#include <bits/stdc++.h>
using namespace std;

int sum_digits(long long n) {
    n = stoll(to_string(n).substr(0, 3));

    return n / 100 + n / 10 % 10 + n % 10 - 1;
}

int main() {

    long long a, n;
    cin >> a >> n;

    for (long long i = 2; i <= n; i++) {
        long long new_a = a + sum_digits(a);
        if (a == new_a) {
            cout << a << endl;
            return 0;
        }

        a = new_a;
    }

    cout << a << endl;
    return 0;

}
