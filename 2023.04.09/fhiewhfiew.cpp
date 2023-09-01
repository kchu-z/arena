#include <bits/stdc++.h>
using namespace std;

int chars[256];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int br = 0;

    unordered_set <int> st;

    for (int i = 0; i < s.size(); i++) {
        br++;
        if (i + 1 == s.size() || s[i] != s[i + 1]) {
            if (s[i] == '0') {
                st.insert(br);
            }

            br = 0;
        }
    }

    cout << st.size() << endl;
    return 0;

}
