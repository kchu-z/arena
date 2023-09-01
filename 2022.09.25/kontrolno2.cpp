#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, m = 0, start = 0;
    cin >> n >> k;
    vector <int> v(n);
    bool f = true;

    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        if (i == n - 1 || v[i] + 1 != v[i + 1]) {
            if (v[start] == 0) m = max(m, v[i] + 1);
            if (v[start] != 0 || v[i] >= k) f = false;
            start = i + 1;
        }
    }

    if (f) cout << "Yes ";
    else cout << "No ";
    cout << m;

    return 0;

}
