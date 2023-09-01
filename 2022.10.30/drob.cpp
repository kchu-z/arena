#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, s1, s2, s3;
    cin >> s;

    int dot = s.find('.'), lbr = s.find('('), pos = 0;

    if (dot == string::npos) {
        s1 = s.substr(pos, -1);
        s2 = "0";
        s3 = "0";
    } else {
        s1 = s.substr(0, dot);
        if (s1.size() == 0) s1 = "0";
        pos = dot + 1;
        if (lbr == string::npos) {
            s2 = s.substr(pos, -1);
            s3 = "0";
        } else {
            s2 = s.substr(pos, lbr - pos);
            if (s2.size() == 0) s2 = "no";
            s3 = s.substr(lbr + 1, s.size() - lbr - 2);
        }
    }

    cout << s1 << ' ' << s2 << ' ' << s3 << endl;

    return 0;

}
