#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    vector <int> v, _count(26);

    for (char i : s) {
        v.push_back(i - 'a');
        _count[i - 'a']++;
    }

    int br = 0;

    vector <pair <int, int>> _count2(26);

    for (int i = 0; i < 26; i++) _count2[i] = {_count[i], i};
    sort(_count2.begin(), _count2.end());

    for (int i = 0; i < v.size(); i++) {
        br++;

        if (br == 3) {
            for (int j = 0; j < 26; j++) {
                int letter = _count2[j].second;
                bool f = true;

                if (letter == v[i]) f = false;
                if (i > 0 && letter == v[i - 1]) f = false;
                if (i + 1 < v.size() && letter == v[i + 1]) f = false;

                if (f) {
                    _count[v[i]]--;
                    _count[letter]++;

                    v[i] = letter;
                    break;
                }
            }

            br = 0;
        }

        if (i + 1 != v.size() && v[i] != v[i + 1]) br = 0;
    }

    for (int i = 0; i < 26; i++) _count2[i] = {_count[i], i};
    sort(_count2.begin(), _count2.end());

    for (int i = 0; i < v.size(); i++) {
        if (_count[v[i]] * 2 > v.size()) {
            for (int j = 0; j < 26; j++) {
                int letter = _count2[j].second;
                bool f = true;

                if (letter == v[i]) f = false;
                if (i > 0 && letter == v[i - 1]) f = false;
                if (i + 1 < v.size() && letter == v[i + 1]) f = false;

                if (f) {
                    _count[v[i]]--;
                    _count[letter]++;

                    v[i] = letter;
                    break;
                }
            }
        }
    }

    string str;
    for (int i : v) str.push_back(i + 'a');

    cout << str << endl;
    return 0;

}
