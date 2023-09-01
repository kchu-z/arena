#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string m, x;
    getline(cin, m);
    int c0 = 0, c1 = 0, start = 0;

    unordered_map <string, bool> v;
    vector <string> s;

    while (cin >> x) {
        sort(x.begin(), x.end());
        s.push_back(x);
    }

    //for (auto i : v) cout << i.first << ' ';

    for (int i = 0; i < m.size(); i++) {
        if (i + 1 == m.size() || isupper(m[i]) != isupper(m[i + 1])) {
            if (isupper(m[i])) {
                string word = m.substr(start, i - start + 1);
                sort(word.begin(), word.end());
                v[word] = true;
            }

            start = i + 1;
        }
    }

    for (string& i : s) {
        if (v[i]) {
            if ((int) i.size() % 2 == 0) c0++;
            else c1++;
        }
    }

    cout << c0 + c1 << endl << c0 << ' ' << c1;

    return 0;

}
