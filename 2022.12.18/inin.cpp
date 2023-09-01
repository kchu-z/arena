#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector <vector <int>> v(n, vector <int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (int r = 0; r < k % 4; r++) {
        vector <vector <int>> s(n, vector <int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s[j][n - i - 1] = v[i][j];
            }
        }

        v = s;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << ' ';
        }

        cout << endl;
    }

    return 0;

}
