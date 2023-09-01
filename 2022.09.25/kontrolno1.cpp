#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, sum = 0, br = 0;
    cin >> n >> k;
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        if (v[i] > k) {
            cout << 0;
            return 0;
        } else sum += v[i];

        if (i == n - 1 || sum + v[i + 1] > k) {
            sum = 0;
            br++;
        }
    }

    cout << br;

    return 0;

}
