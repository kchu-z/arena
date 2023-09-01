#include <bits/stdc++.h>
using namespace std;

int a[1000001], jump1[1000001], jump2[1000001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    jump1[0] = a[0];
    jump1[1] = jump1[0] + a[1];
    jump2[0] = -100;
    jump2[1] = -100;

    for (int i = 2; i < n; i++) {
        jump1[i] = max(jump1[i - 1], jump2[i - 1]) + a[i];
        jump2[i] = jump1[i - 2] + a[i];
    }

    int mn = INT_MIN;
    for (int i = 0; i < n; i++) mn = max(mn, max(jump1[i], jump2[i]));

    cout << mn << endl;
    return 0;

}
