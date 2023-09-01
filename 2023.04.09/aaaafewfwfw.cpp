#include <bits/stdc++.h>
using namespace std;

long long v[100001], prefix[1000001];

long long sum(int a, int b) {
    return prefix[b] - prefix[a - 1];
}

long long f(int l, int r, int n) { /// max за n ученика от l до r
    if (l > r) return -1;
    if (r - l + 1 < n) return -1;
    if (n == 1) return sum(l, r);

    int a = l, b = r; /// граници на n-тия ученик
    long long ans = -1;

    while (a <= b) {
        int m = (a + b) / 2;
        long long sum_of_nth = sum(l, m), max_of_rest = f(m + 1, r, n -1);

        if (sum_of_nth > max_of_rest) b = m - 1;
        else a = m + 1;

        cout << n << ' ' << a << ' ' << b << endl;

        ans = max(ans, max(sum_of_nth, max_of_rest));
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> v[i];
        prefix[i] = prefix[i - 1] + v[i];
    }

    for (int i = 1; i <= m; i++) cout << prefix[i] << ' ';
    cout << endl;

    cout << f(1, m, n) << endl;
    return 0;

}
