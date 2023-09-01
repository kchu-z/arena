#include <bits/stdc++.h>
using namespace std;

long long f(long long n) {
    if (n < 3) return 1;
    return f(n - 2) + f(n - 1);
}

int main() {

    long long n, m;
    cin >> n >> m;

    cout << n * f(m);

    return 0;

}
