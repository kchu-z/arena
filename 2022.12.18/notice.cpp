#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, k, br = 0;
    cin >> m >> n >> k;

    vector <vector <bool>> arr(m + 1, vector <bool> (n + 1));
    vector <vector <int>> prefix(m + 1, vector <int> (n + 1));

    for (int i = 0; i < k; i++) {
        int x, y, size_x, size_y;
        cin >> x >> y >> size_x >> size_y;

        for (int a = 1; a <= size_x; a++) {
            for (int b = 1; b <= size_y; b++) {
                arr[x + a][y + b] = 1;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
        }
    }

    int sx, sy;
    cin >> sx >> sy;

    for (int i = sx; i <= m; i++) {
        for (int j = sy; j <= n; j++) {
            int sum = prefix[i][j] + prefix[i - sx][j - sy] - prefix[i][j - sy] - prefix[i - sx][j];
            if (sum == 0) br++;
        }
    }

    cout << br << endl;
    return 0;

}
