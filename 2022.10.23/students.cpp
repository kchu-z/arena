#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, num, br = 0, mx = 0, idx;
    cin >> n;
    vector <int> v(n);

    for (int i = 1; i <= n; i++) {
        cin >> num;
        v[i] = i - num;
        if (v[i] < 1) v[i] += n;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        br++;
        if (i == n - 1 || v[i] != v[i + 1]) {
            if (mx < br) {
                mx = br;
                idx = v[i] + 1;
            }
            br = 0;
        }
    }

    cout << idx << endl;

    return 0;

}
