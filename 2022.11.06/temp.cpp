#include <bits/stdc++.h>
using namespace std;

int getType(int a, int b) {
    if (a > b) return 0;
    if (a < b) return 1;
    return 2;
}

int main() {

    int n, a, b, c, d;
    cin >> n;
    vector <int> temp(n), type(n), v(3);

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        temp[i] = (a + b + c + d) / 4;
    }

    type[1] = getType(temp[0], temp[1]);

    for (int i = 2; i < n; i++) {
        type[i] = getType(temp[i - 1], temp[i]);

        if (type[i - 1] != type[i]) {
            v[type[i - 1]]++;
        }

        if (i == n - 1) {
            v[type[i]]++;
        }

        cout << v[0] << ' ' << v[1] << ' ';
    }

    return 0;

}

/// 6 2 5 8 6 4 7 9 8 6 8 8 7 4 3 3 1 0 -1 -1 -2 -2 2 3 3
