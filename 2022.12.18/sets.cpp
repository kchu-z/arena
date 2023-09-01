#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, sets = 0;
    cin >> n >> k;
    vector <pair <int, int>> v(n + 1), ans;

    for (int i = 1; i <= k; i++) {
        int b;
        cin >> b;

        for (int j = 0; j < b; j++) {
            int num;
            cin >> num;

            v.push_back({num, i});
        }
    }

    sort(v.begin(), v.end());
    vector <int> br(n + 1);

    int j = -1;

    for (int i = 0; i <= n; i++) {
        while (j + 1 <= n && sets < k) {
            j++;
            if (!br[v[j].second]) sets++;
            br[v[j].second]++;
        }

        if (sets == k) ans.push_back({v[j].first - v[i].first, v[i].first});

        br[v[i].second]--;
        if (br[v[i].second]) sets--;
    }

    sort(ans.begin(), ans.end());

    cout << ans[0].second << ans[0].first + ans[0].second << endl;
    return 0;

}
