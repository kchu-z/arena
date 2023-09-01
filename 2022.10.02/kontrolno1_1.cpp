#include <bits/stdc++.h>
using namespace std;

vector <long long> d(long long n) {
    vector <long long> v;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n == i * i) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }

    sort(v.begin(), v.end());
    return v;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, num, q;
    cin >> n >> q;
    vector <long long> v = d(n);

    for (long long j = 0; j < q; j++) {
        num;
        cin >> num;

        for (long long i : v) {
            if (i >= num) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;

}
