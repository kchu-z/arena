#include <bits/stdc++.h>
using namespace std;

bool simple(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    long long n, sum = 0;
    cin >> n;

    for (long long i = 2; i * i * i * i <= n; i++) {
        if (simple(i)) sum += i * i * i * i;
    }

    cout << sum << endl;

    return 0;

}
