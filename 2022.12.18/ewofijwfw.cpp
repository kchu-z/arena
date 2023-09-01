#include <bits/stdc++.h>
using namespace std;

struct p{
    int first, second;
};

map <p, bool> v;

int check(int x, int y) {
    p pos;
    pos.first = x;
    pos.second = y;

    if (v[pos] == false) {
        v[pos] = true;
        return 1;
    }

    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, k, x, y, br = 0;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        if (x * 2 > m) x = m - x + 1;
        if (y * 2 > n) y = n - y + 1;

        int x2 = m - x + 1, y2 = n - y + 1;

        check(x, y);
        check(x, y2);
        check(x2, y);
        check(x2, y2);
    }

    cout << br << endl;
    return 0;

}
