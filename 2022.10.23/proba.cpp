#include <bits/stdc++.h>
using namespace std;

int main() {

    int br = 0;

    for (int a = 1; a < 10; a++) {
        for (int b = 1; b < 10; b++) {
            if (a != b) {
                for (int c = 1; c < 10; c++) {
                    if (a != c && b != c) {
                        for (int d = 1; d < 10; d++) {
                            if (a != d && b != d && c != d) {
                                if (a + b + c + d == 15) {
                                    cout << a << b << c << d << ' ';
                                    br++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << endl << br << endl;

    return 0;

}
