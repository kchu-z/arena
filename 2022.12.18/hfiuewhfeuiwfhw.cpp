#include <bits/stdc++.h>
using namespace std;

int main() {

    int m, n, a, b, c, d;
    cin >> m >> n >> a >> b >> c >> d;

    int sum = a + b + c + d, idx = 1;

    while (1) {
        if (4 <= m * idx && sum <= n * idx) {
            cout << idx << endl;
            return 0;
        }

        idx++;
    }

    return 0;

}
