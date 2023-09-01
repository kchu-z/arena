#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, num, mxdiff = 0, mx = 0, mn = INT_MAX;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (mn > num) {
            mn = num;
            mx = num;
        } else if (mx < num) {
            mx = num;
        }

        mxdiff = max(mxdiff, mx - mn);
    }

    cout << mxdiff << endl;

    return 0;

}
