#include <bits/stdc++.h>
using namespace std;

int main() {

    /// 9

    long long n;
    cin >> n;

    long long p = 1;

    long long a = n / 10, b = n % 10;

    if (a % 2) p = 9;

    if (b >= 3) p *= 3;
    if (b >= 7) p *= 7;
    if (b >= 9) p *= 9;

    cout << p % 10 << endl;
    return 0;

}
