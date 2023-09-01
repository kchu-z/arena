#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, br = 0;
    cin >> n;

    unordered_set <int> a, b;

    for (int i = 0; i < n; i++) {
        a.insert((i * i) % n);
    }

    for (int x : a) for (int y : a) for (int z : a) {
        b.insert((x + y + z) % n);
    }

    for (int i = 0; i < n; i++) {
        if (b.find(i) == b.end()) {
            br++;
            cout << i << '\n';
        }
    }

    cout << '\n' << br << '\n';

    return 0;

}
