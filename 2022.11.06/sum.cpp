#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, br = 0;
    cin >> n;

    for (int a = 1; a * 4 <= n; a++) {
        for (int b = a; a + b * 3 <= n; b++) {
            for (int c = b; a + b + c * 2 <= n; c++) {
                br++;
            }
        }
    }

    cout << br << endl;

    return 0;

}
