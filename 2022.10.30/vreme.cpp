#include <bits/stdc++.h>
using namespace std;

int main() {

    int br_dvt = 0, br_t = 0;
    string s, str;
    cin >> s;
    vector <string> v;

    for (char& i : s) {
        if (i == ':') br_dvt++;
        else if (i == '.') br_t++;
    }

    if (br_dvt == 0) s = "0:0:" + s;
    else if (br_dvt == 1) s = "0:" + s;
    if (br_t == 0) s += ".000";

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) str.push_back(s[i]);
        if (i + 1 == s.size() || !isdigit(s[i])) {
            v.push_back(str);
            str = "";
        }
    }

    cout << stoi(v[0]) << ' ' << stoi(v[1]) << ' ' << stoi(v[2]) << ' ' << stoi(v[3]) * pow(10, 3 - v[3].size());

    return 0;

}
