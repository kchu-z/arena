#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, mn = INT_MAX;
    cin >> n;
    vector <long long> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mn = min(mn, v[i]);
    }

    long long s = 0;

    for (int i = 0; i < n; i++) s += v[i] - mn;

    cout << s << endl;
    return 0;

}
