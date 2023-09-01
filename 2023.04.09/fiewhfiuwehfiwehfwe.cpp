#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long v[100001];

bool check(long long m) {
    long long br = 0;

    for (int i = 0; i < k; i++) {
        br += m / v[i];
    }

    return n <= br;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    long long l = 0, r = v[0] * n, ans = -1;

    while (l <= r) {
        long long m = (l + r) / 2;

        if (check(m)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    if (ans < 0) exit(1);

    cout << ans << endl;
    return 0;

}
