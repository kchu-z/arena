#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;
    unordered_map <int, int> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        m[num - i * d]++;
    }

    int mx = 0;

    for (pair <int, int> p : m) mx = max(mx, p.second);
    cout << n - mx << endl;

    return 0;

}
