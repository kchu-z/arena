#include <bits/stdc++.h>
using namespace std;

int main() {

    vector <double> v;
    double num;

    while (cin >> num) v.push_back(num);
    v.pop_back();

    int br = 0, n = v.size(), mx = 0;

    for (int i = 0; i < n; i++) {
        br++;
        if (i == n - 1 || v[i] > v[i + 1]) {
            mx = max(mx, br);
            br = 0;
        }
    }

    cout << mx;

    return 0;

}
/// 2.12 2.15 2.15 2.14 2.10 2.21 2.21 2.28 2.25 2.26 0 a
