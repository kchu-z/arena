#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, num, c = 0;
    char s;
    cin >> n >> k;
    vector <char> v(n);

    for (int i = 0; i < k; i++) {
        cin >> num >> s;
        if ((int) v[c] != 0) {
            cout << '!';
            return 0;
        } else v[c] = s;
        c = (c + num) % n;
    }

    for (char i : v) cout << i;

    //for (int i = 0; i < n; i++) {
    //    int x = c - i;
    //    if (x < 0) x = n - x;
    //    if ((int) v[x] == 0) cout << '?';
    //    else cout << v[x];
    //}

    return 0;

}

// 8 8 4 V 3 I 7 T 7 A 6 R 5 N 1 O 9 H
// 5 6 1 A 2 B 5 B 1 C 2 A 2 B
