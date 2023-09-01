#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    stack <int> st;
    int l = 0, r = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            if (st.empty()) l++;
            else st.pop();
        }
    }

    r = st.size();

    cout << l << ' ' << r << endl;
    return 0;

}
