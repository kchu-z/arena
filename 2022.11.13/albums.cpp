#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, num;
    cin >> n >> m;
    unordered_map <int, bool> m1;

    vector <int> ans;

    for (int i = 0; i < n; i++) {
        cin >> num;
        m1[num] = true;
    }

    for (int i = 0; i < m; i++) {
        cin >> num;

        if (m1[num]) ans.push_back(num);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;

    for (int i : ans) cout << i << ' ';

    return 0;

}
