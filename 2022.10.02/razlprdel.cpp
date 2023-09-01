#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    bool f = false;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (f) cout << '*';
            else f = true;
            cout << i;
            n /= i;
        }
    }

    if (n != 1) {
        if (f) cout << '*';
        cout << n;
    }

    return 0;

}
