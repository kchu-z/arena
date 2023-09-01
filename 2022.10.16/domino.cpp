#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, sum = 0, down = 0, a, b;
    cin >> n >> m;
    vector <int> prefix(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        sum += a - b;

        prefix[i] = prefix[i - 1] + a - b;
    }

    sum /= 2;

    for (int i = m; i <= n; i++) {
        if (prefix[i] - prefix[i - m] == sum) {
            cout << i - m + 1;
            return 0;
        }
    }

    cout << "N/A";
    return 0;

}
