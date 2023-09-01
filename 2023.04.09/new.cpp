#include <bits/stdc++.h>
using namespace std;

long long bs(long long n) {
    long long l = 0, r = 1000000000, ans;

    while (l <= r) {
        long long m = (l + r) / 2;

        if (m * m <= n) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }

    return ans;
}

int main() {

    long long n;
    cin >> n;

    cout << bs(n);
    return 0;

}
