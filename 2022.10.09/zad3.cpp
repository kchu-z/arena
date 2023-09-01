#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector <bool> v(n + 1, true);

    for (int i = 2; i <= n; i++) {
        if (v[i] && 2 * i <= n) {
            for (int j = 2 * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (v[i]) cout << i << ' ';
    }

    return 0;

}
