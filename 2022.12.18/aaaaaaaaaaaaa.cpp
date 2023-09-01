#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, a, b, x, y, br = 0;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        if (x <= a && y <= b) br++;
    }

    cout << br << endl;
    return 0;

}
