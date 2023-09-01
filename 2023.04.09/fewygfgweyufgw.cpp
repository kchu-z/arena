#include <bits/stdc++.h>
using namespace std;

string v[100000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sort(v[i].begin(), v[i].end());
    }

    sort(v, v + n);

    long long br = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        br++;
        if (i + 1 == n || v[i] != v[i + 1]) {
            ans += (br - 1) * br / 2;
            br = 0;
        }
    }

    cout << ans << endl;
    return 0;

}
/**
7
14 231 23 41 6 132 123
*/
