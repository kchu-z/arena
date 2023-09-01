#include <bits/stdc++.h>
using namespace std;

int main() {



    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, mx = 0, mxh = 0, h;
    cin >> n >> h;

    stack <long long> st;

    for (int i = 0; i < n; i++) {
        long long u;
        cin >> u;
        if (u >= h) {
            while (st.size()) st.pop();
        } else {
            while (st.size() && st.top() <= u) st.pop();
        }

        st.push(u);

        if (mx < (long long) st.size()) {
            mx = st.size();
            mxh = i;
        }
    }

    cout << mx << endl;
    return 0;

}
