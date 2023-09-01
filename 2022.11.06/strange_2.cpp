#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector <int> br(128);

    int n = s.size(), st = 0, len = 0, pos = 0;

    for (int i = 0; i < 128; i++) br[i] = -1;

    for (int i = 0; i < n; i++) {
        st = max(st, br[s[i]] + 1);

        if (len <= i - st + 1) {
            len = i - st + 1;
            pos = st;
        }

        br[s[i]] = i;
    }

    cout << len << ' ' << pos << endl;
    cout << s.substr(pos, len);

    return 0;

}
