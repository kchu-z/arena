#include <bits/stdc++.h>
using namespace std;

long long v[100001], prefix[1000001];
int n, m;

long long sum(int a, int b) {
    return prefix[b] - prefix[a - 1];
}

bool check(int ans) {
    int j = 0, mn = 100000;

    for (int i = 1; i <= m; i++) {
        while (j + 1 <= m && sum(i - 1, j + 1) <= ans) j++;

        if (i <= j) {
            if (j + 1 <= n) mn = min(mn, j + 2 - i);
        } else j = i;
    }

    return m - mn < n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> v[i];
        prefix[i] = prefix[i - 1] + v[i];
    }

    long long l = 1, r = prefix[m] + 1, ans;

    while (l <= r) {
        long x = (l + r) / 2;

        if (check(x)) {
            ans = x;
            r = x - 1;
        } else l = x + 1;
    }

    cout << ans << endl;
    return 0;

}

