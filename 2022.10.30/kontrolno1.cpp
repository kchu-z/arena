#include <bits/stdc++.h>
using namespace std;
int n, start = 0, dur = 0;

bool isSymmetric(string& a) {
    for (int i = 0; i < a.size() / 2; i++) {
        if (a[i] != a[a.size() - i - 1]) return false;
    }

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    string s, s1;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        s1 = s.substr(0, i);
        reverse(s1.begin(), s1.end());

        string s2 = s + s1;

        if (isSymmetric(s2)) {
            cout << s1.size() << endl << s1;
            return 0;
        }
    }


    return 0;

}
