#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <pair <int, int>> v(n);

    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    vector <int> br(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j].first <= v[i].second) {
                br[i]++;
                br[j]++;
            }
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        mx = max(mx, br[i]);
    }

    cout << mx << endl;

    return 0;

}
/// 5 1 4 3 6 2 5 1 2 6 7
