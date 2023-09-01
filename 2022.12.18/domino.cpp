#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    cin >> n;
    vector <long long> v(n + 1);
    v[0] = 1;
    v[1] = 1;

    for (long long i = 2; i <= n; i++) v[i] = (v[i - 2] + v[i - 1]) % (1000000007);
    cout << v[n] << endl;

    return 0;

}
