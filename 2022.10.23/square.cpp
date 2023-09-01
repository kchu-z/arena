#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, br = 0, num, mx = 0;
    cin >> n;
    unordered_map <int, bool> sq, m;
    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    for (int i = 1; i * i <= mx; i++) sq[i * i] = true;

    for (int i = 0; i < n; i++) {
        if (m[v[i]]) {
            br++;
            break;
        }
        for (int j = 1; j * j < v[i]; j++) {
            if (sq[v[i] - j * j]) {
                br++;
                m[v[i]] = true;
                break;
            }
        }
    }

    cout << br << endl;

    return 0;

}
