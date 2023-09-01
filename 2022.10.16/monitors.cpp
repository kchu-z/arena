#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, sum = 0, mx = 0;
    cin >> n;
    vector <pair <int, int>> v(n);

    for (long long i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());

    for (long long i = 0; i < n; i++) {
        sum += (long long) v[i].second;
        if (i == n - 1 || v[i].first != v[i + 1].first) {
            mx = max(mx, sum);
            sum = 0;
        }
    }

    cout << mx << endl;

    return 0;

}
