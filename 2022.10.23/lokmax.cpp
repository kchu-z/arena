#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, num, mn, prev, f = 0;
    cin >> n;
    vector <int> v;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
        if (num == 0) break;
    }

    n = v.size();

    for (int i = 1; i < n - 1; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            f++;

            if (f == 1) {
                prev = i;
            } else if (f == 2) {
                mn = i - prev - 1;
                prev = i;
            } else {
                mn = min(i - prev - 1, mn);
                prev = i;
            }
        }
    }

    if (f < 2) cout << 0;
    else cout << mn;

    return 0;

}
