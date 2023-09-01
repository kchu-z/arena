#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    stack <int> st;
    vector <bool> v(s.size());
    int br = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            if (st.empty()) continue;
            v[st.top()] = 1;
            v[i] = 1;
            br += 2;
            st.pop();
        }
    }

    cout << br << endl;

    for (int i = 0; i < s.size(); i++) {
        if (v[i]) cout << i << ' ';
    }



    return 0;

}
