#include <bits/stdc++.h>
using namespace std;

long long a[100000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long j = -1, mx = 0;

    for (long long i = 0; i < n; i++) {
        while (j + 1 < n && a[j + 1] - a[i] <= k) {
            j++;
        }

        mx = max(mx, j - i + 1);

        if (j < i) j = i;
    }

    cout << mx << endl;
    return 0;

}
