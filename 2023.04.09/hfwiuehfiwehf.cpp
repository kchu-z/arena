#include <bits/stdc++.h>
using namespace std;

void ins(string& s, int pos, char c) {
    s.push_back(0);

    for (int i = s.size() - 1; i > pos; i--) {
        s[i] = s[i - 1];
    }
    s[pos] = c;
}

bool check(string& s) {
    stack <int> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            if (st.empty()) return 0;
            st.pop();
        }
    }

    return 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long br = 0;

    string s;
    cin >> s;

    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= s.size() + 1; j++) {
            string str = s;
            ins(str, i, '(');
            ins(str, j, ')');

            if (check(str)) br++;
        }
    }

    cout << br << endl;
    return 0;

}
