#include <bits/stdc++.h>
using namespace std;

int main() {

    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

    if (a1 > a2) swap(a1, a2);
    if (b1 > b2) swap(b1, b2);
    if (c1 > c2) swap(c1, c2);

    if (a1 > b1) {
        swap(a1, b1);
        swap(a2, b2);
    }

    if (b1 > c1) {
        swap(c1, b1);
        swap(c2, b2);
    }

    if (a1 > b1) {
        swap(a1, b1);
        swap(a2, b2);
    }

    if (a1)

    return 0;

}
