#include <bits/stdc++.h>
using namespace std;

int n, mn = 0;
string s;

int main() {

    cin >> n >> s;
    vector <int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] + ((s[i - 1] == '<') ? 1 : -1);
        mn = min(mn, v[i]);
    }

    for (int i = 0; i <= n; i++) {
        v[i] -= mn;
        cout << v[i] << ' ';
    }

    return 0;

}
