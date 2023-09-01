#include <iostream>
#include <cmath>
using namespace std;

int n, a[20];

double solve() {
    int mn = a[0], mx = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < mn) mn = a[i];
        else if (a[i] > mx) mx = a[i];
    }

    return (mn + mx) / 2;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    return 0;

}
