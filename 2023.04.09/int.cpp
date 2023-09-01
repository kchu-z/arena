#include <bits/stdc++.h>
using namespace std;

long long a[1000001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int test = 1; test <= 50; test++) {
        ifstream is;
        ofstream os;

        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            unsigned long long x;
            cin >> x;

            a[i] = (a[i - 1] ^ x);
        }

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;

            cout << (a[r] ^ a[l - 1]) << ' ';
        }
    }

    return 0;

}
/**
6 4
3 8 7 12 9 1
1 3
1 6
2 4
4 6
*/
