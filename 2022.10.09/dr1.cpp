#include <bits/stdc++.h>
using namespace std;
vector <int> v(10000001), arr(10000001);

int d(int n) {
    int br = 0;

    while (n > 1) {
        br++;
        n /= v[n];
    }

    return br;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, a, b;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            for (int j = i; j <= n; j += i) v[j] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + d(i);
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }

    return 0;

}
