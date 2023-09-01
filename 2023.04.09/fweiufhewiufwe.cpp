#include <bits/stdc++.h>
using namespace std;

int main() {

    int m = 1;

    for (int i = 1; i <= 77; i++) {
        m = (m * 10) % 49;
        if (m == 1) {
            cout << i;
            exit(0);
        }
    }

    return 0;

}
