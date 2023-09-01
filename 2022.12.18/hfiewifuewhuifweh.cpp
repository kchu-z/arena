#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, m, mn = INT_MIN;
    cin >> n >> m;
    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m && i < n; i++) {
        mn = max(mn, (long long) arr[i][i]);
    }

    cout << mn << endl;

    return 0;

}
