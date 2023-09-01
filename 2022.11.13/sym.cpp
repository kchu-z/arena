#include <bits/stdc++.h>
using namespace std;

bool isSymmetric(string& s) {
    int n = s.size();

    for (int i = 0; i * 2 < n; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (isSymmetric(s)) {
            cout << i + n << endl;
            return 0;
        }

        s.pop_back();
    }

    return 0;

}
