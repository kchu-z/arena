#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, u, w;
    cin >> n >> u >> w;
    vector <long long> v(n + 1), l(n + 2), r(n + 2);

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) l[i] = max(l[i - 1], v[i]);
    for (int i = n - 1; i >= 0; i--) r[i] = max(r[i + 1], v[i + 1]);

    /*for (int i = 0; i <= n; i++) cout << l[i] << ' ';
    cout << endl;
    for (int i = 0; i <= n; i++) cout << r[i] << ' ';
    cout << endl;*/

    long long sum = 0;
    for (int i = 0; i <= n; i++) sum += min(l[i], r[i]);

    cout << sum * u * w << endl;
    return 0;

}
