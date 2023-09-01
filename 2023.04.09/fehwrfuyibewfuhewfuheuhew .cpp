#include <bits/stdc++.h>
using namespace std;

int a[200000];

bool check(int leftIdx, int rightIdx) {
    return a[leftIdx] + a[leftIdx + 1] > a[rightIdx];
}

int solve(int l, int r, int rightIdx) {
    int ans = 200000;

    while (l <= r) {
        int m = (l + r) / 2;

        if (check(m, rightIdx)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    return ans;
}

int main() {

    int n, ans = 1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int r = 2; r < n; r++) {
        ans = max(ans, r + 1 - solve(0, r - 2, r));
    }

    cout << ans << endl;
    return 0;

}
