#include <bits/stdc++.h>
using namespace std;

int d(int n) {
    int br = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            br++;
            if (i * i != n) br++;
        }
    }

    return br;
}

int main() {

    for (int a = 1; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                if (d(1001 * (100 * a + 10 * b + c)) == 32) cout << a << b << c << a << b << c << endl;
            }
        }
    }

    return 0;

}
