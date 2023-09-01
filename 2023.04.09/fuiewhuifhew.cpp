#include <bits/stdc++.h>
using namespace std;

long long c[2001][2001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 2000; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    long long n, br = 0;
    cin >> n;

    vector <pair <long long, int> > divisors;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) divisors.push_back({i, 0});

        while (n % i == 0) {
            divisors.back() = {divisors.back().first, divisors.back().second + 1};
            n /= i;

            br++;
        }
    }

    if (n != 1) {
        divisors.push_back({n, 1});
        br++;
    }

    long long ans = 1;

    for (auto p : divisors) {
        ans *= c[br][p.second];
        br -= p.second;
    }

    cout << ans << endl;
    return 0;

}
