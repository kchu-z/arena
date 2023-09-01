#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mx = 0;
    cin >> n;
    vector <int> v(n), a(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int curr_mx = 0;

        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                curr_mx = max(curr_mx, a[j]);
            }
        }

        a[i] = curr_mx + 1;
        mx = max(mx, a[i]);
    }

    cout << mx << endl;
    return 0;

}
