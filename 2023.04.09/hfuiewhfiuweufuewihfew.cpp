#include <bits/stdc++.h>
using namespace std;

unsigned long long c[21][21];

int c1[256], c2[256];

long long fact(long long n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}



int main() {

    unsigned long long ans = 0, stringsize;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 20; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    cout << 0 << endl;
    return 0;

}
/**
wefhi
q
*/
