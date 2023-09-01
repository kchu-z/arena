#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, br = 0, sqdiv = 1;
    cin >> n;

    if (n == 1) br = 1;
    else for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            br++;
            sqdiv = i;
        }
    }

    cout << br << ' ' << 2 * (sqdiv + n / sqdiv) << endl;

    return 0;

}
