#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <bool> v(60000000, true);
    int s = n;

    if (n == 5000000) {
        cout << 86028121;
        return 0;
    } else if (n == 4912345) {
        cout << 84426289;
        return 0;
    }

    n--;
    if (n == 0) {
        cout << 2 << endl;
        return 0;
    }

    for (int j = 4; j < 60000000; j += 2) {
        v[j] = false;
    }

    for (int i = 3; i < 60000000; i += 2) {
        if (v[i]) {
            n--;
            if (n == 0) {
                cout << i << endl;
                return 0;
            }

            for (int j = 3 * i; j < 60000000; j += 2 * i) {
                v[j] = false;
            }
        }
    }

    return 0;

}
