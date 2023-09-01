#include <bits/stdc++.h>
using namespace std;

bool isWhole(double x) {
    return x == floor(x);
}

int main() {

    for (int i = 10; i < 100; i++) {
        if (i % 10 != 0 && i % ((i / 10) * (i % 10)) == 16) cout << i << ' ';
    }

}
