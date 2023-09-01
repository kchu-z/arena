#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, prev = -1;
    cin >> n;

    queue <int> st;
    unordered_map <int, bool> m;

    for (int i = 0; i < n; i++) {
        int t, num;
        cin >> t >> num;

        if (t == 1) {
            st.push(num);
            if (prev == -1) prev = num;
        } else {
            m[num] = true;
            while (!st.empty() && m[st.front()]) st.pop();

            if (st.empty()) prev = -1;
            else prev = st.front();
        }

        cout << prev << ' ';
    }

    return 0;

}
