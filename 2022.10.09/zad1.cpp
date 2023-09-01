#include <bits/stdc++.h>
using namespace std;

int main() {

    int m, n;
    cin >> m >> n;
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i * (ceil(m * 1.0 / i)); j <= n; j += i) sum++;
    }

    cout << sum << endl;

    return 0;

}
