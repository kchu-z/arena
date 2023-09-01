#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k, num, br = 0;
    cin >> n >> k;
    vector <char> v(n);
    char s;

    cin >> num >> s;
    v[0] = s;

    for (int i = 1; i < k; i++) {
        cin >> num >> s;
        br = (br + num) % n;

        if (v[br] == 0 || v[br] == s) {
            v[br] = s;
        } else {
            cout << '!';
            return 0;
        }
    }

    for (int i = br; i >= 0; i--) {
        if (v[i] == 0) {
            cout << '?';
        } else cout << v[i];
    }

    for (int i = n - 1; i > br; i--) {
        if (v[i] == 0) {
            cout << '?';
        } else cout << v[i];
    }

    return 0;

}

// 8 8 4 V 3 I 7 T 7 A 6 R 5 N 1 O 9 H
// 5 6 1 A 2 B 5 B 1 C 2 A 2 B
