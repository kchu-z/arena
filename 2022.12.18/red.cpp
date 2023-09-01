#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, num;
    cin >> n >> k;
    vector <int> v(n), s(n), val(100001);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s[i] = val[v[i]];
        val[v[i]]++;
    }

    for (int i = 0; i < k; i++) {
        cin >> num;
        num--;

        cout << s[num] << ' ' << val[v[num]] - s[num] - 1 << '\n';
    }

    return 0;

}
