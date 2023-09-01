#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    bitset <100001> p;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        p = (p | (p << x));
        p[x] = 1;

        //cout << p << endl;
    }

    int br = 0;

    for (int i = a; i <= b; i++) br += p[i];

    cout << br << endl;
    return 0;
}
