#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <int> v(n), a(n);
    vector <pair <int, bool>> b(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    a[0] = v[0];
    a[1] = v[0] + v[1];
    b[0] = a[0];
    b[1] = a[1];

    for (int i = 2; i < n; i++) {
        a[i] = a[i - 1] + v[i];

        if (b[i].second) {

        }
    }

    cout << a[n - 1] << endl;
    return 0;

}
