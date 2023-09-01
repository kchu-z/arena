#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, x, y, mx = 0;
    cin >> n >> a >> b;

    vector <vector <int>> arr(1000001, vector <int> (51));

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        int a2 = max(0, x - a);
        int b2 = max(0, y - b);

        for (int A = x; A > a2; A--) {
            for (int B = y; B > b2; B--) {
                arr[A][B]++;
            }
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        for (int j = 1; j <= 50; j++) {
            mx = max(mx, arr[i][j]);
        }
    }

    cout << mx << endl;
    return 0;

}
