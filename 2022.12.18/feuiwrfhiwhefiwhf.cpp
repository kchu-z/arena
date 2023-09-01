#include <bits/stdc++.h>
using namespace std;

int br = 0;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    cin >> a >> b;

    long long p = a * b;

    for (long long i = 2; i * i <= b; i++) {
        if (p % i == 0 && __gcd(i, p / i) == a) {
            br++;
        }
    }

    cout << br << endl;
    return 0;

}
