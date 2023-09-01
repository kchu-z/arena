#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, br = 0, num, p = 1;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> num;
        p *= num;
    }

    if (p == 1) {
        cout << 1;
        return 0;
    }

    for (long long i = 2; i <= p; i++) {
        if (p % i == 0) {
            br++;
            while (p % i == 0) p /= i;
        }
    }

    if (p != 1) br++;
    cout << br;
    return 0;

}
