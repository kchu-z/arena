#include <bits/stdc++.h>
using namespace std;

string s, new_str;

void f(int pos) {
    if (pos < 0) return;

    if (pos == 0) {
        new_str.push_back(s[0]);
        return
    }

    if (pos == 1) {
        if (s[0] != s[1]) {
            new_str.push_back(s[1]);
            new_str.push_back(s[0]);
        }

        return;
    }

    if ()
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    return 0;

}
