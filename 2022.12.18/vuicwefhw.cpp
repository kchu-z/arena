#include <bits/stdc++.h>
using namespace std;

long long power(int k) {
    if (k == 0) return 1;
    return 3 * power(k - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mn = 0;
    cin >> n;
    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mn += v[i];
    }

    int mx = power(v.size());

    for (int i = 0; i < mx; i++) {
        int k = i;

        vector <int> w(3);

        for (int j = 0; j < v.size(); j++) {
            w[k % 3] += v[j];
            k /= 3;
        }

        mn = min(mn, max(w[0], max(w[1], w[2])));
    }

    cout << mn << endl;
    return 0;

}
