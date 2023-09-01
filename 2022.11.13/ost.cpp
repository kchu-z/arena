#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s, mn, mx;

    cin >> mn >> mx;
    if (cmp(mx, mn)) swap(mn, mx);

    for (int i = 2; i < n; i++) {
        cin >> s;

        if (cmp(mn, s)) {
            if (cmp(mx, s)) {
                mn = mx;
                mx = s;
            } else {
                mn = s;
            }
        }
    }

    cout << mn;

    return 0;

}
