#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, br = 0;
    cin >> n;
    vector <int> arr(n);
    vector <pair <int, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        arr[v[i].second] = br;
        br++;
        if (i == n - 1 || v[i].first != v[i + 1].first) br = 0;
    }

    for (int i : arr) cout << i << ' ';

    return 0;

}
