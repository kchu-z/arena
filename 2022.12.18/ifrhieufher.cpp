#include <bits/stdc++.h>
using namespace std;

int main() {

    vector <long long> v(1000001, 1), prefix(1000001);

    for (int i = 2; i <= 500000; i++) {
        for (int j = 2 * i; j <= 1000000; j += i) v[j] += i;
    }

    for (int i = 2; i <= 1000000; i++) prefix[i] = prefix[i - 1] + (v[i] >= i);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        cout << prefix[r] - prefix[l - 1] << '\n';
    }


    return 0;

}
