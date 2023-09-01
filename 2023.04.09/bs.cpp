#include <bits/stdc++.h>
using namespace std;

vector <long long> v(100001);
long long disks, computers;

bool check(long long t) {
    long long ans = 0;

    for (int i = 0; i < computers; i++) ans += t / v[i];

    return disks <= ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> disks >> computers;
    for (int i = 0; i < computers; i++) cin >> v[i];

    long long l = 0, r = 10000000000, ans;

    while (l <= r) {
        long long m = (l + r) / 2;

        if (check(m)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << ans << endl;
    return 0;

}
