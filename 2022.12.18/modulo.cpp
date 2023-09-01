#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;
    vector <long long> v(n / 5000 + 1, 1), s(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> s[i];

        v[i / 5000] *= s[i];
        v[i / 5000] %= m;
    }

    for (int i = 0; i < n; i++) {
        long long p = 1;

        for (int j = 0; j < v.size(); j++) {
            if (j != i / 5000) {
                p *= v[j];
                p %= m;


            } else {
                for (int k = j * 5000; k < min((int) n, (j + 1) * 5000); k++) {
                    if (k != i) {
                        p *= s[k];
                        p %= m;
                    }
                }
            }
        }

        cout << p << ' ';
    }

    return 0;

}
/*
5 10
1 2 4 3 7
*/
