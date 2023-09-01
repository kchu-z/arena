#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector <int> v(n + 1);
    stack <int> st;
    st.push(0);

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) {
        while (st.size() != 0 && v[st.top()] >= v[i]) st.pop();

        if (st.size() == 1) cout << "-1 ";
        else cout << st.top() << ' ';

        st.push(i);
    }

    return 0;

}
