#include <bits/stdc++.h>
using namespace std;

int n, l, r, houses, totalhouses, ans = INT_MAX, stamp;
vector <pair <int, int>> delta{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector <vector <int>> v, visited;
vector <string> arr;
vector <int> cells, heights;
pair <int, int> post;

int dfs(pair <int, int> p) {
    int br = 0;

    if (p.first < 0 || n <= p.first) return 0;
    if (p.second < 0 || n <= p.second) return 0;
    if (v[p.first][p.second] < l || r < v[p.first][p.second]) return 0;
    if (visited[p.first][p.second] == stamp) return 0;

    if (arr[p.first][p.second] == 'K') br++;

    for (auto dir : delta) {
        pair <int, int> cell = {p.first + dir.first, p.second + dir.second};
        br += dfs(cell);
    }

    return br;
}

bool check(int L, int R) {
    l = L;
    r = R;

    stamp++;
    dfs(post) != totalhouses;
    exit(0);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n;

    v.resize(n);
    arr.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 'K') totalhouses++;
            else if (arr[i][j] == 'P') post = {i, j};
        }
    }

    for (int i = 0; i < n; i++) {
        v[i].resize(n);
        visited[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            cells.push_back(v[i][j]);
        }
    }

    sort(cells.begin(), cells.end());

    for (int i = 0; i < cells.size(); i++) {
        if (i + 1 == cells.size() || cells[i] != cells[i + 1]) heights.push_back(cells[i]);
    }

    for (int i : heights) cout << i << ' ';
    cout << endl;

    int j = -1;

    for (int i = 0; i < heights.size(); i++) {

        while (j + 1 < heights.size() && check(heights[i], heights[j + 1])) j++;
        //while (j + 1 < heights.size()) j++;
        return 2;
        cout << heights[i] << ' ' << heights[j] << endl;
        if (j + 1 < heights.size()) ans = min(ans, heights[j + 1] - heights[i]);

        if (j < i) j = i;
    }

    cout << ans << endl;
    return 0;

}
