#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, n, m;
    cin >> a >> n >> m;
    n -= a - 1;

    vector <bool> v(n);

    for (long long i = 0; i < m; i++) {
        long long num;
        cin >> num;
        num -= a;

        v[num] = 1;
    }

    vector <long long> s;
    long long br = 0;

    for (long long i = 0; i < n; i++) {
        if (v[i] == 0) br++;

        if (i == n - 1 || v[i + 1] == 1) {
            s.push_back(br);
            br = 0;
        }
    }

    long long sum = m;
    for (long long i : s) sum += i / 2;

    cout << sum << endl;
    return 0;

}
