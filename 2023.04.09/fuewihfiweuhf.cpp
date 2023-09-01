#include <bits/stdc++.h>
using namespace std;

int main() {

    unsigned long long n, br = 0;
    cin >> n;

    while (n) {
        unsigned long long cuberoot = cbrt(n);
        cuberoot *= cuberoot * cuberoot;
        br += n / cuberoot;
        n %= cuberoot;
    }

    cout << br << endl;
    return 0;

}
