#include <bits/stdc++.h>
using namespace std;

long long n, k, mx = 0;
vector <long long> v(100000);

bool canWrite(long long time) {
    long long s = 0;

    for (int i = 0; i < k; i++) s += time / v[i];

    return s >= n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    long long left = 0, right = mx * n, ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canWrite(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;

}
