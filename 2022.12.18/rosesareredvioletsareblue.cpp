#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long m, n, br = 0;
    cin >> m >> n;

    vector <vector <long long>> arr(m + 1, vector <long long> (n + 1));
    vector <vector <long long>> prefix(m + 1, vector <long long> (n + 1));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char s;
            cin >> s;

            if (s == '.') arr[i][j] = '.';
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int x1 = 1; x1 <= m - 2; x1++) {
        for (int x2 = x1 + 2; x2 <= m; x2++) {
            for (int y1 = 1; y1 <= n - 2; y1++) {
                if (arr[x1][y1] == '.' || arr[x2][y1] == '.') continue;
                for (int y2 = y1 + 2; y2 <= n; y2++) {
                    if (arr[x1][y1] == '.' || arr[x2][y1] == '.') continue;

                    long long sum1 = prefix[x2][y2] + prefix[x1 - 1][y1 - 1] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1];
                    long long sum2 = prefix[x2 - 1][y2 - 1] + prefix[x1][y1] - prefix[x1][y2 - 1] - prefix[x2 - 1][y1];

                    if (sum1 - sum2 == 0) br++;
                }
            }
        }
    }

    cout << br << endl;
    return 0;

}
/// 4 7 *****..*..*********.*...****
