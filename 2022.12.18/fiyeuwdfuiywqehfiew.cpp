#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int br = 0;

    string s;
    cin >> s;
    vector <bool> ans(s.size());
    stack <int> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            if (st.empty()) continue;
            ans[st.top()] = 1;
            ans[i] = 1;

            br += 2;
            st.pop();
        }
    }

    cout << br << endl;

    for (int i = 0; i < s.size(); i++) {
        if (ans[i]) cout << i << ' ';
    }

    return 0;

}
