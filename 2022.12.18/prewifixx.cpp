#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q;
    cin >> n;
    vector <long long> v(n + 1), p(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];
    cin >> q;

    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + v[i];

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << p[b] - p[a - 1] << '\n';
    }

    return 0;

}
