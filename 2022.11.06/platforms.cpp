#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];

int main() {

    int m, n, br = 0;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i - 1][j] != arr[i][j] && arr[i][j - 1] != arr[i][j]) br++;
        }
    }

    cout << br << endl;

    return 0;

}
