#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack <int> st;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == '(') st.push(i);
        else {
            if (st.empty()) return 0;
            st.pop();
        }
    }

    return 1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    long long br = 0;

    for (int i = 0; i <= s.size(); i++) {

        for (int j = 0; j <= s.size() + 1; j++) {
            string str = s;

            if (check(str)) br++;
        }
    }

    cout << br << endl;
    return 0;

}

