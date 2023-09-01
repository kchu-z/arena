#include <bits/stdc++.h>
using namespace std;

int d(int n) {
    int br = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            br++;
            n /= i;
        }
    }

    if (n != 1) br++;
    return br;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, a, b;
    cin >> n >> q;
    vector <int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] + d(i);
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << v[b] - v[a - 1] << '\n';
    }

    return 0;

}
