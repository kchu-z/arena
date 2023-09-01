#include <bits/stdc++.h>
using namespace std;

bool check(string& s, int l, int r) {
    stack <int> st;

    for (int i = l - 1; i < r; i++) {
        if (s[i] == '(') st.push(i);
        else {
            if (st.empty()) return 0;
            st.pop();
        }
    }

    return st.empty();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin >> n >> s >> k;

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;

        cout << check(s, l, r) << '\n';
    }

    return 0;

}
