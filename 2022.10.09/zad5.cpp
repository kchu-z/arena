#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k, p, q, br = 0;
    cin >> n >> k;
    vector <int> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    cin >> p >> q;
    vector <int> v(q - p + 2);

    for (int i : h) {
        for (int j = p - 1 + i - ((p - 1) % i); j <= q; j += i) {
            v[j - p]++;
        }
    }

    for (int i : v) {
        if (i == k) br++;
    }

    cout << br << endl;

    return 0;

}
