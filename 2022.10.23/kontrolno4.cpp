#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, br = 0;
    cin >> n >> k;
    vector <bool> v(1000001);
    vector <int> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        v[s[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        if (k - s[i] >= 0 && v[k - s[i]]) br++;
    }

    cout << br / 2 << endl;

    return 0;

}
