#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int br = 0, c = 0;

    string s;
    cin >> s;
    unordered_map <int, bool> v;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') br++;
        if (i + 1 == s.size() || s[i] != s[i + 1]) {
            if (br == 0) continue;

            if (!v[br]) {
                c++;
                v[br] = true;
            }

            br = 0;
        }
    }

    cout << c << endl;

    return 0;

}
