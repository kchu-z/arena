#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, str;
    cin >> s;
    vector <string> v;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ':') {
            if (i != 0 && s[i - 1] == ':') {
                v.push_back("0");
                v.push_back("0");
            } else v.push_back(str);
            str = "";
        } else str.push_back(s[i]);
    }

    if (str != "") v.push_back(str);

    for (string i : v) {
        //string z;
        //for (int j = 0; j < 4 - i.size(); j++) z.push_back('0');
        cout << i << ' ';
    }

    return 0;

}
