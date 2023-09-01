#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m, sum = 0;
    cin >> n >> m;

    for (long long i = 0; i < n; i++) {


        for (long long j = 0; j < m; j++) {
            long long newNum = (i + 1) * (n - i);
            newNum %= 1000000007;
            newNum *= j + 1;
            newNum %= 1000000007;
            newNum *= m - j;
            newNum %= 1000000007;
            long long a;
            cin >> a;
            newNum *= a;
            newNum %= 1000000007;
            sum += newNum;
            sum %= 1000000007;
        }
    }

    cout << sum << endl;

    return 0;

}
