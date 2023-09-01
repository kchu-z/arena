#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin >> n >> k;

    vector <pair <double, pair <long long, long long>>> v;

    for (long long a = 1; a < n; a++) {
        for (long long b = a + 1; b <= n; b++) {
            long long nod = gcd(a, b);

            if (nod == 1) {
                pair <long long, long long> p = {a, b};
                v.push_back({a * 1.0 / b, p});
            }
        }
    }

    sort(v.begin(), v.end());

    //for (auto p : v) cout << p.second.first << ' ' << p.second.second << endl;

    auto p = v[k - 1].second;

    cout << p.first << ' ' << p.second << endl;
    return 0;

}
