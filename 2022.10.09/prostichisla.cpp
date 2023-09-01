#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool simple(int n) {
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int br = 0;

    for (int i = 2; i <= 100000000; i++) {
        if (simple(i)) {
            br++;
            cout << br << '\t' << i << endl;
        }
    }

    return 0;

}
