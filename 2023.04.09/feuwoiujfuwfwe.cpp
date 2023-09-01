#include <bits/stdc++.h>
using namespace std;

int X[500001], Y[500001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y, mn = INT_MAX;
    cin >> n >> x >> y;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        if (num == x) X[i] = i;
        else X[i] = X[i - 1];

        if (num == y) Y[i] = i;
        else Y[i] = Y[i - 1];

        mn = min(mn, abs(X[i] - Y[i]));
    }


    cout << mn << endl;
    return 0;

}
