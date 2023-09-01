#include <bits/stdc++.h>
using namespace std;

long long power(long long exp) {
    if (exp <= 0) return 1;

    if (exp % 2 == 0) {
        long long x = power(exp / 2);
        return x * x % 1000000007;
    }

    return power(exp - 1) * 2 % 1000000007;
}

int main() {

    long long n;
    cin >> n;

    cout << power(n - 1) << endl;

    return 0;

}
