#include <bits/stdc++.h>
using namespace std;

long long fib(long long n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    return fib(n - 2) + fib(n - 1);
}

int main() {

    long long n;
    cin >> n;

    cout << fib(n) << ' ' << fib(n + 1) << endl;

    return 0;

}
