#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, a, b;
    cin >> n >> q;
    vector <bool> v(n + 1, true);
    vector <int> arr(n + 1), s(n + 1);

    for (int i = 2; i <= n; i++) {
        if (v[i]) {
            s.push_back(i);
            for (int j = 2 * i; j <= n; j += i) v[j] = false;
        }
    }

    for (int p : s) {
        if (p == 0) continue;
        for (int i = 1; i * p <= n; i++) {
            arr[i * p] = arr[i] + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }

    return 0;

}
