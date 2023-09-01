#include <bits/stdc++.h>
using namespace std;

int ex(int n) {
    int br = 0;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            br++;
            n /= i;
        }
    }

    if (n != 1) br++;

    return br;
}

int main() {

    int n, s = 0;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        s += ex(i);
    }

    cout << s << endl;
    return 0;

}
