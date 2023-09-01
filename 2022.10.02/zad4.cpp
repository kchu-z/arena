#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector <long long> v;

    long long n, i, j = 1;
    bool f = false;
    cin >> n;

    if (n == 1) v.push_back(n);
    else {
        for (i = 2; i * i <= n; i += j) {
            while (n % i == 0) {
                v.push_back(i);
                n /= i;
            }

            if (i == 3) j++;
        }
    }

    if (n != 1) v.push_back(n);

    sort(v.begin(), v.end());

    for (i = 0; i < v.size(); i++) {
        if (f) cout << '*';
        else f = true;
        cout << v[i];
    }

    return 0;

}
