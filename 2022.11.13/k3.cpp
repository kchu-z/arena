#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int bs(long long num, vector <long long>& v) {
    long long l = 1, r = v.size() - 1;
    long long ans = v.size();

    while (l <= r) {
        long long m = (l + r) / 2;

        if (v[m] >= num) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, q, num;
    cin >> n >> q;
    vector <long long> v(n + 1);

    for (long long i = 1; i <= n; i++) {
        cin >> num;
        v[i] = v[i - 1] + num;
    }

    //v.erase(v.begin());

    //sort(v.begin(), v.end());
    //for (int i = 0; i < n; i++) cout << v[i] << ' ';
    //cout << endl;

    for (long long i = 0; i < q; i++) {
        cin >> num;
        cout << bs(num, v) << endl;
    }

    return 0;

}
/// 9 6 2 3 3 2 5 1 6 1 1 20 24 12 10 10 2
