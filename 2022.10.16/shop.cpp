#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k, sum = 0;
    cin >> n >> k;
    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = k - 1; i < n; i += k) sum -= v[i];

    cout << sum << endl;

    return 0;

}
