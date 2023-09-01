#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, d = 0;
    cin >> n;
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++) {
        d = max(d, v[i + 1] - v[i]);
    }

    cout << d << endl;

    return 0;

}
