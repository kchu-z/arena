#include <bits/stdc++.h>
using namespace std;

void lower(string& a) {
    for (char& i : a) {
        if (isupper(i)) i = i - 'A' + 'a';
    }
}

int main() {

    int n, br1 = 0, br2 = 0, br3 = 0, br4 = 0;
    string a, b, c, d;
    char s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        lower(a);lower(b);lower(d);lower(d);
        if (a[0] == s) br1++;
        if (d[d.size() - 1] == s) br4++;

        if (b.find(s) != string::npos) br2++;
        if (c.find(s) != string::npos && c.substr(c.find(s) + 1, -1).find(s) != string::npos) br3++;
    }

    cout << br1 << ' ' << br2 << ' ' << br3 << ' ' << br4 << endl;

    return 0;

}
/// 3 a Anin Miraj Masa Bala Taralej toto Dani Kana ananas pile ananas Tapa
