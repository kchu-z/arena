#include <bits/stdc++.h>
using namespace std;
string s, str;

string toleft(int pos) {
    string str;

    for (int i = pos; i >= 0; i--) str.push_back(s[i]);
    for (int i = s.size() - 1; i > pos; i--) str.push_back(s[i]);

    return str;
}

string toright(int pos) {
    string str;

    for (int i = pos; i < s.size(); i++) str.push_back(s[i]);
    for (int i = 0; i < pos; i++) str.push_back(s[i]);

    return str;
}

int main() {

    int n, d;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> d;
        s.push_back(d + '0');
    }

    for (int i = 0; i < n; i++) {
        str = max(str, max(toleft(i), toright(i)));
        //cout << toleft(i) << ' ' << toright(i) << ' ' << max(toleft(i), toright(i)) << endl;
    }

    cout << str;
    return 0;

}
