#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b, bool check) {
    if (check) {
        if (a[0] == '-' && b[0] != '-') return true;
        if (a[0] != '-' && b[0] == '-') return true;
        if (a[0] == '-' && b[0]) return cmp(b, a, false);
    }

    int dotPosA = a.find('.');
    int dotPosB = b.find('.');

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

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, str;
    getline(cin, s);
    vector <string> v;

    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) continue;
        if (s[i] == '.') continue;
        if (s[i] == '-') continue;

        s[i] = '_';
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            if (i == 0 || i == n - 1 || !isdigit(s[i - 1]) || !isdigit(s[i + 1])) s[i] = '_';
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i == n - 1 || !isdigit(s[i + 1])) continue;

            if (i == 0 || !isdigit(s[i - 1]) && s[i - 1] != '.') {
                if (i < n - 2 && s[i + 1] == '.' && isdigit(s[i + 2])) continue;
                s[i] = '_';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            if (i == n - 1 || !isdigit(s[i + 1])) s[i] = '_';
        }
    }

    ///cout << s << endl << endl << endl;

    for (int i = 0; i < n; i++) {
        if (s[i] != '_') {
            str.push_back(s[i]);
        }

        if (i == n - 1 || s[i + 1] == '-' || s[i + 1] == '_') {
            if (str == "") continue;
            v.push_back(str);
            str = "";
        }
    }

    ///sort(v.begin(), v.end(), cmp, true);

    int N = v.size();

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (cmp(v[i], v[j], true)) swap(v[i], v[j]);
        }
    }

    cout << v[N - 1] << endl;

    return 0;

}
