#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool f = true;

    string v;
    cin >> v;

    do {
        f = false;
        vector <pair <char, int>> s;
        string _new;
        int br = 0, n = v.size();
        for (int i = 0; i < n; i++) {
            br++;
            if (i == n - 1 || v[i] != v[i + 1]) {
                s.push_back(make_pair(v[i], br));
                br = 0;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i].second < 3) for (int j = 0; j < s[i].second; j++) _new.push_back(s[i].first);
            else f = true;
        }

        v = _new;
    } while (v.size() > 2 && f);

    if (v.size() == 0) cout << "EMPTY";
    else cout << v;

    return 0;

}
