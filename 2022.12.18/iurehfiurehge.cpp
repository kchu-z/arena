#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long m, n;
    cin >> m >> n;

    cout << m / __gcd(m, n);
    return 0;

}
