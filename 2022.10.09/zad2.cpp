#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector <int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            v[j]++;
        }
    }

    int mx = v[1], ix = 1;

    for (int i = 2; i <= n; i++) {
        if (mx < v[i]) {
            mx = v[i];
            ix = i;
        }
    }

    cout << ix << endl << mx;

    return 0;

}
