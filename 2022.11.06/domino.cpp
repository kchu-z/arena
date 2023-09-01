#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k, a, b, up = 0, down = 0;
    cin >> n >> k;
    vector <int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        up += a;
        down += b;

        v[i] = v[i - 1] + a - b;
    }

    for (int i = k; i <= n; i++) {
        int curr_up = up - v[i] + v[i - k];
        int curr_down = down + v[i] - v[i - k];

        if (curr_up == curr_down) {
            cout << i - k + 1 << endl;
            return 0;
        }
    }

    cout << "N/A\n";
    return 0;

}
