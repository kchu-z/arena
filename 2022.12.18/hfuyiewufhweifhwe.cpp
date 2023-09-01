#include <bits/stdc++.h>
using namespace std;

vector <int> v(256);

char bs(unordered_map <char, bool> invalid) {
    int mn = INT_MAX;

    for (int i : v) {
        if (invalid[i]) continue;
        mn = min(mn, i);
    }
    return (char) mn;
}

int main() {

    string v;
    cin >> v;

    int br = 0;

    for (char& i : v) v[i]++;

    for (int i = 0; i < v.size(); i++) {
        br++;
        if (i != n - 1 && v[i] != v[i + 1]) br = 0;

        if (br == 3) {
            br = 0;

            unordered_map <char, bool> m;
            m[s[i]] = true;
            m[s[i - 1]] = true;
            m[s[i + 1]] = true;
        }
    }

    return 0;

}
