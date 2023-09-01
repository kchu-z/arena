#include <bits/stdc++.h>
using namespace std;

int main() {

    int m, n, k, dig = 0;
    cin >> m >> n >> k;

    char arr[m][n];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) arr[i][j] = '.';

    if (k != 0) {
        for (int i = 0; i < n; i++) {
            if (m == 1 || i % (m - 1) == 0) {
                for (int j = 0; j < m; j++) {
                    arr[j][i] = dig + '0';
                    dig = (dig + 1) % k;
                }
            } else {
                arr[m - 1 - i % (m - 1)][i] = dig + '0';
                dig = (dig + 1) % k;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << arr[i][j];
        cout << endl;
    }

    return 0;

}
