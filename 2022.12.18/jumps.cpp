#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> v(n);

    priority_queue <int> free;
    priority_queue <pair <int, int>> busy;

    for (int i = 1; i <= n; i++) free.push(-i);

    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].second = -v[i].second;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        while (!busy.empty() && busy.top().first >= -v[i].first) {
            free.push(busy.top().second);
            busy.pop();
        }

        if (!free.empty()) {
            busy.push({v[i].second - v[i].first, free.top()});
            free.pop();
        } else {
            pair <int, int> temp = busy.top();
            busy.pop();
            busy.push({temp.first + v[i].second, temp.second});
        }
    }

    vector <pair <int, int>> ans;

    while (!busy.empty()) {
        ans.push_back({busy.top().first, busy.top().second});
        busy.pop();
    }

    sort(ans.begin(), ans.end());

    for (auto p : ans) cout << -p.first << ' ' << -p.second << endl;

    //cout << -ans[0].first << ' ' << -ans[0].second << endl;
    return 0;

}
