#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a, b, sum = 0;
    cin >> a >> b;

    if (a > b) swap(a, b);

    while (a) {
        sum += b / a;
        b %= a;

        swap(a, b);
    }

    cout << sum << endl;
    return 0;

}
