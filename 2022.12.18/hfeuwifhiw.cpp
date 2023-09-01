#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, br = 0;
    cin >> n;
    int _min = INT_MAX, _min_pos = -1;

    vector <int> v(n), m(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == i) continue;
        br++;

        swap(v[i], v[m[i]]);
        swap(m[i], m[v[m[i]]]);
    }

    cout << br << endl;
    return 0;

}
