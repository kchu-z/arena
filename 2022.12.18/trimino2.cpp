#include <bits/stdc++.h>
using namespace std;

bool isAdjacent(pair <int, int>& a, pair <int, int>& b) {
    int distanceX = abs(b.first - a.first), distanceY = abs(b.second - a.second);
    if (min(distanceX, distanceY) == 0 && max(distanceX, distanceY) == 1) return true;
    return false;
}

int solve() {

    int m, n, num;
    cin >> m >> n;
    unordered_map <int, vector <pair <int, int>>> v;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;

            v[num].push_back({i, j});
        }
    }

    if (v[0].size() > 2) {
        cout << "NO\n";
        return 0;
    }

    for (auto& i : v) {
        if (i.first == 0) continue;

        if (i.second.size() != 3) {
            cout << "NO\n";
            return 0;
        }

        int br = 0;
        vector <pair <int, int>>& pos = i.second;

        if (isAdjacent(pos[0], pos[1])) br++;
        if (isAdjacent(pos[0], pos[2])) br++;
        if (isAdjacent(pos[1], pos[2])) br++;

        if (br != 2) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) solve();

    return 0;

}
