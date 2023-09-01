#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, str;
    cin >> s;
    vector <string> v;

    bool f = false;
    int c = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ':') str.push_back(s[i]);

        if (i + 1 == s.size() || s[i] == ':') {
            v.push_back(str);
            str = "";
        }
    }

    for (string i : v) {
        if (i == "") c++;
    }

    for (string i : v) {
        if (i == "") {
            if (!f) {
                f = true;

                int br = 8 + c - v.size();

                for (int i = 0; i < br; i++) {
                    cout << "0 ";
                }
            }

        } else cout << i << ' ';
    }

    return 0;

}
