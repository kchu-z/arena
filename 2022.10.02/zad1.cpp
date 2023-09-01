#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, br = 0;
    cin >> n;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) br++;
            else br += 2;
        }
    }

    cout << br;

    return 0;

}
