#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, m, br = 0, sum = 0;
    cin >> n >> m;
    vector <bool> v(n);
    char s;

    for (int i = 0; i < n; i++) {
        bool f = true;

        for (int j = 0; j < m; j++) {
            cin >> s;
            if (s == '.') f = false;
        }

        v[i] = f;
    }

    /*for (int i = 0; i < n; i++) {
        cout << v[i];
    }

    cout << endl;*/

    for (int i = 0; i < n; i++) {
        if (v[i]) br++;
        if (i == n - 1 || !v[i + 1]) {
            //cout << br * (br + 1) / 2 << endl;
            sum += br * (br + 1) / 2;
            br = 0;
        }
    }

    cout << sum << endl;

    return 0;

}
/// 5 6 ******************..*...******
