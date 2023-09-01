#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector <int> sieve(1000001);

    for (int i = 2; i <= 1000000; i++) {
        if (!sieve[i]) {
            for (int j = i; j <= 1000000; j += i) sieve[j] = i;
        }
    }

    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << sieve[num] << ' ';
    }

    return 0;

}
