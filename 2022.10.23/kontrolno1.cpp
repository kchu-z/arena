#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num = 0, mx = 0;
    cin >> n;
    unordered_map <int, int> m, k;

    for (int i = 0; i < n; i++) {
        cin >> num;
        m[num] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        k[num] = i;
    }

    n++;

    for (int i = 1; i < n; i++) {
        mx = max(mx, abs(m[i] - k[i]));
    }

    cout << mx << endl;

    return 0;

}
