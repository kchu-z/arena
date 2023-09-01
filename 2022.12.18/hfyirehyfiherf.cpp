#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector <int> sieve(1000001), br(1000001);

    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j <= 1000000; j += i) sieve[j] = i;
        }
    }

    int n, mx = 0, mx1, mx2;
    cin >> n;
    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        v[i] = sieve[num];
    }

    int j = -1;

    for (int i = 0; i < n; i++) {
        while (j + 1 < n && br[v[j + 1]] < 1) {
            j++;
            br[v[j]]++;

            cout << i << ' ' << j << '\n';
        }

        if (j - i + 1 > mx) {
            mx = j - i + 1;
            mx1 = i;
            mx2 = j;
        }

        if (i <= j) br[v[i]]--;
        else j = i;
    }

    cout << mx1 + 1 << ' ' << mx2 + 1 << endl;
    return 0;

}
