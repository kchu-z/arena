#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map <char, bool> vowel;
    vowel['a'] = 1;
    vowel['e'] = 1;
    vowel['i'] = 1;
    vowel['o'] = 1;
    vowel['u'] = 1;
    vowel['y'] = 1;

    int br = 0;
    string s;
    cin >> s;

    vector <int> v;

    for (int i = 0; i < s.size(); i++) {
        if (i + 1 == s.size() || vowel[s[i]] != vowel[s[i + 1]]) {
            v.push_back(i - br  + 1);
            br = i + 1;
        }
    }

    int sum = 0;

    for (int i : v) sum += (i - 1) / 2;

    cout << sum << endl;
    return 0;

}
