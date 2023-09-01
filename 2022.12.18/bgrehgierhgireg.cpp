#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int br = 0;
    char s;
    stack <char> st;

    while (cin >> s) {
        if (s == 'O') {
            if (st.empty() || st.top() != 'L') {
                st.push(s);
                br++;
            }
        } else if (s == 'T') {
            while (!st.empty() && st.top() == 'O') {
                st.pop();
                br--;
            }

            st.push(s);
        } else st.push(s);
    }

    cout << st.size() << ' ' << br << endl;
    return 0;

}
