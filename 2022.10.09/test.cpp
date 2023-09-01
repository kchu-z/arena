#include <bits/stdc++.h>
using namespace std;

const int n = 86028222;

int main() {

    int k, br = 0;
    cin >> k;
    vector <bool> v(n + 1, true);

    for (int i = 2; i <= n; i++) {
        if (v[i] && 2 * i <= n) {
            for (int j = 2 * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (v[i] == 0) {
            br++;

            if (br == k) {
                cout << i;
                return 0;
            }
        }
    }

    return 0;

}
