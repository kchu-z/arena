#include <bits/stdc++.h>
using namespace std;

bool simple(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {

    int n;
    cin >> n;

    if (simple(n)) {
        cout << 1 << endl << n;
    } else {
        if (n % 2 == 0) {
            cout << 2 << endl;
            int fl = floor(n * 1.0 / 2), cl = ceil(n * 1.0 / 2);
            for (int i = 0; fl - i > 1; i++) {
                if (simple(fl - i) && simple(cl + i)) {
                    cout << fl - i << ' ' << cl + i << endl;
                    return 0;
                }
            }
        } else {
            if (simple(n - 2)) {
                cout << 2 << endl << 2 << ' ' << n - 2;
                return 0;
            }
            cout << 3 << endl << 3 << ' ';
            n -= 3;
            int fl = floor(n * 1.0 / 2), cl = ceil(n * 1.0 / 2);
            for (int i = 0; fl - i > 1; i++) {
                if (simple(fl - i) && simple(cl + i)) {
                    cout << fl - i << ' ' << cl + i << endl;
                    return 0;
                }
            }
        }
    }

    return 0;

}
