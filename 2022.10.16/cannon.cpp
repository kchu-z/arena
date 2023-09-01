#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, a, b;
    cin >> n >> q;
    vector <bool> v(n + 1, true);
    vector <int> p, br(n + 1), prefix(n + 1);

    for (int i = 2; i <= n; i++) {
        if (v[i]) {
            p.push_back(i);
            for (int j = 2 * i; j <= n; j += i) v[j] = false;
        }
    }

    for (int j : p) {
        br[j] = 1;
        for (int i = 2; i * j <= n; i++) {
            br[j * i] = br[i] + 1;
        }
    }

    for (int i = 1; i < br.size(); i++) {
        prefix[i] = prefix[i - 1] + br[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }

    return 0;

}
