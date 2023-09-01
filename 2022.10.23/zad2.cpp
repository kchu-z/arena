#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, br = 0, mn = 0;
    string a, b;
    cin >> n;
    vector <pair <string, bool> > v(2 * n);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[2 * i] = {a + b, false};
        cin >> a >> b;
        v[2 * i + 1] = {a + b, true};
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 2 * n; i++) {
        if (v[i].second) br++;
        else br--;

        if (i == 2 * n - 1 || v[i].first != v[i + 1].first) {
            mn += abs(br);
            br = 0;
        }
    }

    cout << mn << endl;

    return 0;

}
