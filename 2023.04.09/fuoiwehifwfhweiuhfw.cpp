#include <bits/stdc++.h>
using namespace std;

int n, a[30], mx;
bool f;

void solve() {
    mx = 0;

    int br = 0;
    bool is_decreasing = true;

    for (int i = 0; i < n; i++) {
        br++;
        if (i + 1 == n || a[i] < a[i + 1]) {
            if (mx < br) {
                mx = br;
                f = is_decreasing;
            }

            br = 0;
            is_decreasing = true;
        } else if (a[i] == a[i + 1]) {
            is_decreasing = false;
        }
    }

    cout << mx << ' ' << (f ? "YES" : "NO") << endl;
}

void io() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve();
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) io();


    return 0;

}
