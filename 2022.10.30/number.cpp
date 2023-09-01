#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a, b, i = 2, br = 0;
    cin >> a >> b;

    while (i * (i + 1) < a) i++;
    while (i * (i + 1) <= b) {
        i++;
        br++;
    }

    cout << br << endl;

    return 0;

}
