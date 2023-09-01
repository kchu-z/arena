#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, str;
    unordered_map <char, int> v;

    int mx = 0;

    while (cin >> str) s += str;

    for (char& i : s) {
        if (isalpha(i)) {
            v[toupper(i)]++;
        }
    }

    for (char i = 'A'; i <= 'Z'; i++) {
        mx = max(mx, v[i]);
    }

    for (int i = 0; i < mx; i++) {
        for (char z = 'A'; z <= 'Z'; z++) {
            if (mx - i <= v[z]) cout << z;
            else cout << ' ';
        }
        cout << endl;
    }

    cout << "--------------------------\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

    return 0;

}
