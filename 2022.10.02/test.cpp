#include <bits/stdc++.h>
using namespace std;

bool simple(int n) {

    if (n < 2) return false;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
       if (n % i == 0) return false;
       if (n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {

    for (int i = 4; i < 1000; i += 2) {
        for (int j = 0; i - j >= 2; j += 2) {
            if (simple((i / 2) - j)) {
                cout << i << '\t' << simple((i / 2) + j);
                break;
            }
        }
    }

    return 0;

}
