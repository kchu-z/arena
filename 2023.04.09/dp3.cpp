#include <bits/stdc++.h>
using namespace std;

int w[1000001], v[1000001];

int f(int n, int t) {
    if (t <= 0) return 0;
    if (n == 1 && t >= w[n]) return v[n];
    if (n == 1 && t < w[n]) return 0;

    return max(f(n - 1, t), f(n - 1, t - w[n]) + v[n]);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    cout << f(n, t) << endl;

    return 0;

}
