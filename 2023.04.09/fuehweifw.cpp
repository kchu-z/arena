#include <bits/stdc++.h>
using namespace std;

int main() {

    for (int i = 100; i <= 999; i++) {
        if (floor(sqrt(i)) == sqrt(i)) cout << i << ' ';
    }

    return 0;

}
