#include <bits/stdc++.h>
using namespace std;

int d(int n) {
    int br = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            br++;
            if (n != i * i) br++;
        }
    }

    return br;
}

int main() {

    int x[29] = {};

    for (int i = 1; i <= 2020; i++) {
        int sum = i % 10 + i % 100 / 10 + i % 1000 / 100 + i / 1000;
        x[sum]++;
    }

    for (int i = 1; i <= 28; i++) cout << i << ' ' << x[i] << endl;

    return 0;

}
