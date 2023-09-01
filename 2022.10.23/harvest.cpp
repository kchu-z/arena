#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long mx;
    cin >> n;
    vector <long long> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    mx = max(v[0] + v[1] + v[n - 1], v[0] + v[n - 2] + v[n - 1]);

    for (int i = 1; i < n - 1; i++) {
        mx = max(mx, v[i - 1] + v[i] + v[i + 1]);
    }

    cout << mx << endl;

    return 0;

}
