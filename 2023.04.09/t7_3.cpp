#include <bits/stdc++.h>
using namespace std;

long long a[1000000], sol[1000000];
vector <pair <int, int>> dq;

pair <int, int> bs(int l, int r, int i) {
    int ans = dq.size(), idx = dq.size();

    while (l <= r) {
        int m = (l + r) / 2;

        if (dq[m].first + i <= 0) {
            ans = dq[m].second;
            idx = m;
            r = m - 1;
        } else l = m + 1;
    }

    return {ans, idx};
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, range = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }


    for (int i = n - 1; i >= 0; i--) {
        while (dq.size() > range && dq.back().first <= a[i]) dq.pop_back(); /// yes

        pair <int, int> ans = bs(range, dq.size() - 1, i);
        range = ans.second;
        if (ans.first < 0) sol[i] = n;
        else sol[i] = ans.first - 1;

        dq.push_back({a[i], i});
    }

    for (int i = 0; i < n; i++) {
        int idx = sol[i];

        /**for (int j = i; j < n; j++) {
            if (a[j] + i > 0) {
                idx = j;
                break;
            }
        }**/

        cout << idx - i << ' ';
    }

    return 0;

}

