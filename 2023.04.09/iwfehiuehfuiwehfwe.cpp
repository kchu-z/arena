#include <bits/stdc++.h>
using namespace std;

int main() {

    for (int a = 1; a <= 25; a++) {
        for (int b = a; b <= 25; b++) {
            for (int c = b; c <= 25; c++) {
                if (a + b + c == 25 && a * b * c == 360) cout << a << ' ' << b << ' ' << c << endl;
            }
        }
    }

    return 0;


}
