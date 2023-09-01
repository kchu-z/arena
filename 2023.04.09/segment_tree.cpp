#include <bits/stdc++.h>
#define DEFAULT INT_MAX
using namespace std;

long long a[250001], st[1000001];

long long ex(long long x, long long y) {
    return min(x, y);
}

void dfs(int idx, int tl, int tr) {
    if (tl == tr) {
        st[idx] = a[tl];
        return;
    }

    int m = (tl + tr) / 2;

    dfs(2 * idx, tl, m);
    dfs(2 * idx + 1, m + 1, tr);

    st[idx] = ex(st[idx * 2], st[idx * 2 + 1]);
}

void change(int idx, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        if (tl == pos) st[idx] = val;
        return;
    }

    if (tl > pos || tr < pos) return;

    int m = (tl + tr) / 2;

    change(2 * idx, tl, m, pos, val);
    change(2 * idx + 1, m + 1, tr, pos, val);

    st[idx] = ex(st[idx * 2], st[idx * 2 + 1]);
}

long long mini(int idx, int tl, int tr, int ql, int qr) {
    if (qr < tl || tr < ql) return DEFAULT;
    if (ql <= tl && tr <= qr) return st[idx];

    int m = (tl + tr) / 2;

    return ex(mini(2 * idx, tl, m, ql, qr), mini(2 * idx + 1, m + 1, tr, ql, qr));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        char s;
        cin >> s;

        int x = (s == '(') ? 1 : -1;

        a[i] = a[i - 1] + x;
    }
    cin >> q;

    dfs(1, 1, n);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << (((mini(1, 1, n, l, r) - a[l - 1]) >= 0) && (a[r] - a[l - 1] == 0)) << '\n';
    }

    return 0;

}
/**
10 6
1 7 5 2 3 4 9 6 4 8
1 5
5 6
8 8
5 10
1 10
2 3
*/
