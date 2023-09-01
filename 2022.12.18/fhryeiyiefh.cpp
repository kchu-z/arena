#include <bits/stdc++.h>
using namespace std;

int main() {

    int mx = 0;

    vector <int> v(3), s(3);
    cin >> v[0] >> v[1] >> v[2] >> s[0] >> s[1] >> s[2];

    sort(v.begin(), v.end());
    sort(s.begin(), s.end());

    do {
        int br = 0;

        for (int i = 0; i < 3; i++) {
            if (v[i] >= s[i]) br++;
        }

        mx = max(mx, br);
    } while (next_permutation(s.begin(), s.end()));

    cout << mx << endl;
    return 0;

}

db
