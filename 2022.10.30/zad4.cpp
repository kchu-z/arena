#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, s, x, br = "";
    int c = 0, c1 = 0, c2 = 0;
    getline(cin, s);
    vector <string> v;

    while (cin >> x) {
        sort(x.begin(), x.end());
        v.push_back(x);
    }

    for (int i = 0; i < s.size(); i++) {
        br += s[i];
        if (i + 1 == s.size() || s[i + 1] == ' ' || s[i + 1] == '.' || s[i + 1] == ',') {
            sort(br.begin(), br.end());

            for (string j : v) {
                if (br == j) {
                    c++;
                    if (br.size() % 2 == 0) c2++;
                    else c1++;
                }
            }

            i++;
            br = "";
        }
    }

    cout << c1 << ' ' << c2;

    return 0;

}
