#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, br = 0;
    cin >> n;
    vector <long long> v(n), right(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    stack <long long> st, restore;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.top()] <= v[i]) st.pop();
        br += st.size();

        st.push(i);
    }

    st = restore;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && v[st.top()] < v[i]) st.pop();
        br += st.size();

        st.push(i);
    }

    cout << br << endl;
    return 0;

}
