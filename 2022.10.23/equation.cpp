#include <bits/stdc++.h>
using namespace std;

int main() {

    int a, b, l, br = 0;
    cin >> a >> b >> l;
    vector <bool> v(l + 1);

    for (int i = a; i <= l; i += a) {
        for (int j = b; i + j <= l; j += b) {
            if (!v[i + j]) {
                v[i + j] = true;
                br++;
            }
        }
    }

    cout << l - br << endl;

    return 0;

}
