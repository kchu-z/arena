#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v(100001), s(100000);

void solve(int start) {
    if (start == n) return;
    int idx = start;

    if (start != 0) {
        //v[start] = v[start + 1];
    }
    if (1) {
        for (int i = start + 1; i <= n; i++) {
            if (v[idx] <= v[i]) {
                 for (int j = idx; j < i; j++) s[j] = v[idx];
                 if (v[idx] != v[i]) idx = i;
            }
        }

        solve(idx);
    }
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    solve(0);

    for (int i = 0; i < n; i++) cout << s[i] << ' ';

    return 0;

}
