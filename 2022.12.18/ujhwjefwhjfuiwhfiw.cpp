#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, total = 0;
    cin >> m >> n;

    vector <vector <int>> arr(m + 1, vector <int> (n + 1));
    vector <vector <int>> prefix(m + 1, vector <int> (n + 1));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char s;
            cin >> s;

            if (s == '*') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + arr[i][j];
        }
    }

    for (int x1 = 1; x1 <= m; x1++) {
        for (int x2 = x1 + 2; x2 <= m; x2++) {
            int br_columns = 0, br_invalid = 0, current_br = 0;

            for (int y = 1; y <= n; y++) {
                if (arr[x1][y] == 1 && arr[x2][y] == 1) {
                    if (prefix[x2][y] - prefix[x1 - 1][y] == x2 - x1 + 1) {
                        br_columns++;
                        if (prefix[x2][y - 1] - prefix[x1 - 1][y - 1] == x2 - x1 + 1) br_invalid++;
                    }
                }

                if (arr[x1][y] == 0 || arr[x2][y] == 0 || y == n) {
                    current_br += br_columns * (br_columns - 1) / 2;
                    br_columns = 0;
                }
            }

            total += current_br - br_invalid;
        }
    }

    cout << total << endl;
    return 0;

}
