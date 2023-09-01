#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int n = s.size();

    for (char& i : s) {
        if (!isdigit(i) && i != '-' && i != '.') i = 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            if (i == 0 || i == n - 1) s[i] = 0;
            else if (!(isdigit(s[i - 1]) && isdigit(s[i + 1]))) s[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {

        }
    }

    return 0;

}
