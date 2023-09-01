#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, k;
    cin >> m >> n >> k;
    vector <vector <char>> arr(m, vector <char> (n, '.'));
    arr[0][0] = '0';
    arr[m - 1][0] = (m - 1) % k + '0';

    for (int j = 1; j < m - 1; j++) arr[j][0] = (arr[j - 1][0] - '0' + 1) % k + '0';

    if (1 < n) arr[m - 1][1] = (arr[m - 1][0] - '0' + 1) % k + '0';

    if (2 < n) {
        arr[m - 1][2] = (arr[m - 1][1] - '0' + 1) % k + '0';

        for (int j = m - 2; j > 0; j--) arr[j][2] = (arr[j + 1][2] - '0' + 1) % k + '0';
    }


    for (int i = 2; i < n; i += 4) {
        arr[0][i] = (arr[0][i - 2] - '0' + 2 * m) % k + '0';
        if (i + 1 < n) arr[0][i + 1] = (arr[0][i] - '0' + 1) % k + '0';

        if (i + 2 < n) {
            arr[0][i + 2] = (arr[0][i + 1] - '0' + 1) % k + '0';

            for (int j = 1; j < m - 1; j++) arr[j][i + 2] = (arr[j - 1][i + 2] - '0' + 1) % k + '0';
        }
    }

    for (int i = 4; i < n; i += 4) {
        arr[m - 1][i] = (arr[m - 1][i - 2] - '0' + 2 * m) % k + '0';
        if (i + 1 < n) arr[m - 1][i + 1] = (arr[m - 1][i] - '0' + 1) % k + '0';

        if (i + 2 < n) {
            arr[m - 1][i + 2] = (arr[m - 1][i + 1] - '0' + 1) % k + '0';

            for (int j = m - 2; j > 0; j--) arr[j][i + 2] = (arr[j + 1][i + 2] - '0' + 1) % k + '0';
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << arr[i][j];
        cout << '\n';
    }

    return 0;

}
