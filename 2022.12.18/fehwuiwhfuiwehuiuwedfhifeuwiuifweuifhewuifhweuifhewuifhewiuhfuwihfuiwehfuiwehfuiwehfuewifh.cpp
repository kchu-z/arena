#include <bits/stdc++.h>
using namespace std;

int n;
string chars = "abcdefghijklmnopqrstuvwxyz";
unordered_map <char, char> m;

char mod(int m) {
    int x = (m - n) % 26;

    if (x < 0) return chars[x + 26];
    return chars[x];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    cin >> n;
    n %= 26;

    for (char c : chars) {
        m[c] = mod(c - 'a');
        m[toupper(c)] = toupper(mod(c - 'a'));
    }

    for (char c : s) {
        if (m.find(c) != m.end()) {
            cout << m[c];
        } else cout << c;
    }

    return 0;

}
