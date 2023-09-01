#include <bits/stdc++.h>
using namespace std;

int dotPos(string& s) {
    int pos = s.find('.');

    if (pos == string::npos) return s.size();
    return pos;
}

bool cmp(string& a, string& b, bool check) {
    if (check) {
        if (a[0] == '-' && b[0] != '-') return true;
        if (a[0] != '-' && b[0] == '-') return false;
        if (a[0] == '-') return cmp(b, a, false);
    }

    int dotPosA = dotPos(a);
    int dotPosB = dotPos(b);

    if (dotPosA != dotPosB) return dotPosA < dotPosB;

    for (int i = 0; i < max(a.size(), b.size()); i++) {
        if (i == dotPosA) continue;

        char A = '0', B = '0';

        if (i < a.size()) A = a[i];
        if (i < b.size()) B = b[i];

        if (A != B) return A < B;
    }

    return false;
}

int main() {

    string s;
    getline(cin, s);

    vector <string> v;
    unordered_map <string, string> m;

    s = " " + s + " ";
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (isdigit(c)) continue;
        if (c == '.' && isdigit(s[i - 1]) && isdigit(s[i + 1])) continue;
        if (c == '-' && isdigit(s[i + 1])) continue;

        s[i] = ' ';
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '-' || (isdigit(s[i]) && s[i - 1] == ' ')) v.push_back("");
        if (s[i] != ' ') v.back().push_back(s[i]);
    }

    string ans = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (cmp(ans, v[i], true)) ans = v[i];
        else if (!cmp(v[i], ans, true) && v[i].size() < ans.size()) ans = v[i];
    }

    cout << ans << endl;
    return 0;

}
