#include <bits/stdc++.h>
using namespace std;

int toLeft(string s) {
    int br = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') {
            if (i > 0) s[i - 1] = 0;
        } else if (s[i] == 'B') {
            if (i > 0) s[i - 1] = 0;
            if (i > 1) s[i - 2] = 0;
        }
    }

    for (char& i : s) {
        if (i == '-') br++;
    }

    return br;
}

int toRight(string s) {
    reverse(s.begin(), s.end());
    int br = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') {
            if (i > 0) s[i - 1] = 0;
        } else if (s[i] == 'B') {
            if (i > 0) s[i - 1] = 0;
            if (i > 1) s[i - 2] = 0;
        }
    }

    for (char& i : s) {
        if (i == '-') br++;
    }

    return br;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << max(toLeft(s), toRight(s)) << ' ';
    }

    return 0;

}
