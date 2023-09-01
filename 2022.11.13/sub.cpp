#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    string mn = s;
    reverse(s.begin(), s.end());
    string mx = s;

    int idx = 0, n = s.size();

    //while (idx < n && mn[idx] == '0') idx++;
    //if (idx != n) swap(mn[0], mn[idx]);

    //cout << mn << endl << mx << endl;

    bool f = false;
    string s1;

    for (int i = n - 1; i >= 0; i--) {
        int diff = mx[i] - mn[i];
        if (f) {
            diff--;
            f = false;
        }

        if (diff < 0) {
            diff += 10;
            f = true;
        }

        s1.push_back(diff + '0');
    }

    reverse(s1.begin(), s1.end());

    while (idx < n && s1[idx] == '0') idx++;
    if (idx != n) {
        for (int i = idx; i < n; i++) cout << s1[i];
    } else cout << 0;

    return 0;

}
