#include <bits/stdc++.h>
using namespace std;

int main() {

    for (int a = 1; a <= 1000; a++) {
        for (int b = 1; b <= 1000; b++) {
            if ((double) (a + b) == a * (b + 12) / 6.00) {
                cout << a + b << endl;
            }
        }
    }

    return 0;

}
