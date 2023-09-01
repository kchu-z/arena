#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num, mn = INT_MAX, mx = 0, br = 0;
    cin >> n;
    unordered_map <int, bool> m;

    for (int i = 0; i < n; i++) {
        cin >> num;
        mn = min(mn, num);
        mx = max(mx, num);

        if (m[num]) break;
        else m[num] = true;

        if (i == mx - mn) {
            br++;
            //cout << i << ' ';
        }
    }

    cout << br << endl;

    return 0;

}
/// 6 3 1 2 4 6 5
