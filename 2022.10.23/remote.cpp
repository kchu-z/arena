#include <bits/stdc++.h>
using namespace std;

double a;

bool check(int x, int y) {
    return x < -a || x > a || y < -a || y > a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y, mx = 100000;
    cin >> n >> a;

    a /= 2;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (check(x, y)) mx = min(mx, abs(x) + abs(y));
    }

    cout << mx << endl;

    return 0;

}
