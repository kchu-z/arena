#include <bits/stdc++.h>
using namespace std;

int arr[202][202], a[202][202], b[202][202], c[202][202], d[202][202];

int main() {

    int m, n, h;
    cin >> m >> n >> h;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j + 1] = max(a[i][j], arr[i][j]);
            b[i + 1][j] = max(b[i][j], arr[i][j]);
        }
    }

    for (int i = m; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            c[i][j - 1] = max(c[i][j], arr[i][j]);
            d[i - 1][j] = max(d[i][j], arr[i][j]);
        }
    }

    /*for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << b[i][j] << ' ';
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << c[i][j] << ' ';
        }

        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << ' ';
        }

        cout << endl;
    }

    cout << endl;*/
    int br = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (h <= arr[i][j] || (h <= a[i][j] && h <= b[i][j] && h <= c[i][j] && h <= d[i][j])) {
                br++;
            }
        }
    }

    cout << br << endl;

    return 0;

}
/// 3 4 5 7 7 4 4 6 3 7 3 6 7 6 2
