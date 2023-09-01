#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 4;
    vector <string> v(n);

    string mx;

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    do {
        string ans;
        for (int i = 0; i < n; i++) ans += v[i];

        mx = max(mx, ans);
    } while (next_permutation(v.begin(), v.end()));

    cout << mx << endl;
    return 0;

}
