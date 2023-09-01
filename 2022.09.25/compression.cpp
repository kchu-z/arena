#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string v, s;
    cin >> v;
    v.pop_back();
    int br = 0, n = v.size();

    for (int i = 0; i < n; i++) {
        br++;
        if (v[i] == '1') {
            s.push_back('a' + br - 1);
            br = 0;
        }
    }

    for (char i : s) cout << i;

    return 0;

}
