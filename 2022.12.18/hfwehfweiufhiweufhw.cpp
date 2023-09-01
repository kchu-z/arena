#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long j = -1, br = 0;
    for (int i = 0; i < n; i++) {
        while (j + 1 < n && v[j + 1] - v[i] <= k) j++;
        br += n - j - 1;

        //cout << i << ' ' << j << endl;

        if (j < i) j = i;
    }

    cout << br << endl;
    return 0;

}
