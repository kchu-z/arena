#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    vector <bool> v(10);

    char c;
    bool f = false;

    for (char& i : s) {
        if (v[i - '0']) {
            c = i;
            f = true;
        } else v[i - '0'] = true;
    }

    if (f) cout << c;
    else cout << "No";

    return 0;

}
