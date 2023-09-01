#include <bits/stdc++.h>
using namespace std;

int main() {

    long long m, n, sum = 0;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long num, curr;
            cin >> num;

            curr = (i + 1) * (m - i);
            curr %= 1000000007;

            curr *= (j + 1) * (n - j);
            curr %= 1000000007;

            curr *= num;
            curr %= 1000000007;

            sum += curr;
            sum %= 1000000007;
        }
    }

    cout << sum << endl;
    return 0;

}
