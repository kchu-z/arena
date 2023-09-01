#include <bits/stdc++.h>
#define oo 1e9
using namespace std;

int a[1001];

int sol(int x, int k) {
    int sum = 0;

    for (int i = 1; i <= k; i++) {
        x = a[x];
        sum += x;
        if (sum % k == 0) return 1;
    }

    return oo;
}

int main() {

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int ans = sol(i, k);
        if (ans == oo) ans = 0;
        cout << ans << ' ';
    }
    return 0;

}
