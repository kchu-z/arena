#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool simple(int n) {
    if (n < 2) return false;

    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }

    return true;
}

int d(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return i;
    }

    return n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int s = floor(sqrt(n));

    for (int i = s; i > 1; i--) {
        if (simple(i)) {
            int x = n - (n % i);
            while (d(x) != i) x -= i;
            cout << x << endl;
            return 0;
        }
    }

    return 0;

}
