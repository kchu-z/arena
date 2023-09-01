#include <bits/stdc++.h>
using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k = 0, br = 0;
    cin >> n;
    vector <long long> s(n);

    for (long long i = 0; i < n; i++) {
        cin >> s[i];
        k = max(k, s[i]);
    }

    vector <long long> v(k + 1);

    for (long long i : s) {
        v[i]++;
    }

    for (long long i = 1; i <= k; i++) {
        br += v[i] * (v[i] - 1) / 2;

        for (long long j = 2 * i; j <= k; j += i) {
            br += v[i] * v[j];
        }
    }

    cout << br;

    return 0;

}
