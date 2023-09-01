#include <bits/stdc++.h>
using namespace std;

string a, b;
int k;

bool check(int m) {
    int br = 0, lower = 0, pos = a.find(b, 0);

    while (pos != string::npos) {
        pos = a.find(b, pos + b.size());
        br++;
    }

    return br >= k;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> k;

    int n = a.size(), M = b.size();

    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (check(m)) {
            l = m + 1;
            ans = m;
        } else r = m - 1;
    }

    cout << ans << endl;
    return 0;

}
