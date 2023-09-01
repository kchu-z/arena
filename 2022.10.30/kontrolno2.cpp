#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, w;
    int c0 = 0, c1 = 0;
    getline(cin, s);
    unordered_map <string, bool> words;
    vector <string> v;

    while (cin >> w) {
        sort(w.begin(), w.end());
        v.push_back(w);
    }
    w = "";

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) w.push_back(s[i]);
        if (i + 1 == s.size() || isalpha(s[i]) != isalpha(s[i + 1])) {
            if (isalpha(s[i])) {
                sort(w.begin(), w.end());
                words[w] = true;
                w = "";
            }
        }
    }



    for (string& i : v) {
        if (words[i]) {
            if (i.size() % 2 == 0) c0++;
            else c1++;
        }
    }

    cout << c0 + c1 << endl << c0 << ' ' << c1 << endl;

    return 0;

}
