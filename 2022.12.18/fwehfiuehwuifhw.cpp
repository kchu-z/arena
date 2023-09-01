#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, mx = INT_MAX;
    cin >> m >> n;
    vector <queue <int>> s(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;

            s[i].push(num);
        }
    }


    for (int row = 0; row < m; row++) {
        int sum = 0;

        vector <queue <int>> v = s;

        for (int i = 0; i < m; i++) {
            if (i == row) continue;
            int br = 0;

            while (v[row] != v[i] && br <= n) {
                int num = v[i].front();

                v[i].pop();
                v[i].push(num);

                br++;
            }

            if (br > n) {
                cout << -1 << endl;
                return 0;
            }

            sum += br;
        }

        mx = min(mx, sum);
    }

    cout << mx << endl;
    return 0;

}
