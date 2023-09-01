#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, sum = 0;
    cin >> n >> m;
    vector <int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < min(n, m); i++) {
        sum += a[i] * b[i];
    }

    cout << min(n, m) << ' ' << sum;

    return 0;

}
