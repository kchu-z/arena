#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    //vector <pair <char, int>> v;
    vector <bool> br(94);

    /*for (int i = 0; i < s.size(); i++) {
        v.push_back({s[i], i});
    }*/

    //sort(v.begin(), v.end());

    int i = 0, j = -1, n = s.size(), ans = 0, pos = 0;

    /*for (i; i < n; i++) {
        while (j + 1 < n && br[s[j + 1] - '!'] == false) {
            br[s[j + 1] - '!'] = true;
            j++;
        }

        if (ans <= j - i + 1) {
            ans = j - i + 1;
            pos = i;
        }

        br[s[i] - '!'] = false;

        //cout << i << ' ' << j << endl;
    }

    cout << ans << ' ' << pos << endl << s.substr(pos, ans);
    */

    return 0;

}
