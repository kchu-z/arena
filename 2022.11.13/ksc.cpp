#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, mx = 0;
    cin >> n >> k;
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int i = 0, j = -1, sum = 0;

    for (i; i < n; i++) {
        while (j < n - 1 && sum + v[j + 1] <= k) {
            j++;
            sum += v[j];
        }

        mx = max(mx, sum);
        sum = 0;

        if (j < n - 1 && v[j + 1] > k) {
            i = j + 2;
            j++;
        }
    }

    cout << mx << endl;

    return 0;

}
