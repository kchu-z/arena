#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector <int> v(n), br;
    vector <bool> s(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int st = 0;
    while (!s[st]) {
        br.push_back(st);
        s[st] = true;

        st = v[st];
    }

    int pos = -1, br1 = 0;

    for (int i : br) {
        pos++;

        if (i == st) break;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == false) br1++;
    }

    cout << pos << ' ' << n - pos - br1 << ' ' << br1 << endl;

    return 0;

}
/// 10 8 0 7 6 1 6 2 9 3 6
