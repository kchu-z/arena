#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> edges[1001];
vector <int> vertices(1001);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, br = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        edges[a].push_back({w, b});
        edges[b].push_back({w, a});
    }

    cin >> s;
    priority_queue <pair <int, int>> pq;
    unordered_map <int, bool> visited;

    /**do {
        for (auto p : edges[s]) {
            pq.push({-(vertices[s] + p.first), p.second});
        }

        while (pq.size() && visited.find(pq.top().second) != visited.end()) pq.pop();
        if (pq.empty()) continue;

        auto p = pq.top();
        pq.pop();

        vertices[p.second] = -p.first;

        s = p.second;
        visited.insert(s);
    } while (pq.size());
    */

    int ogs = s;

    do {
        for (auto p : edges[s]) {
            pq.push({-(vertices[s] + p.first), p.second});
            //cout << s << ' ' << vertices[s] + p.first << ' ' << p.second << endl;
        }

        while (pq.size() && visited[pq.top().second]) pq.pop();
        if (pq.empty()) continue;

        auto p = pq.top();
        pq.pop();

        vertices[p.second] = -p.first;

        s = p.second;
        br++;
        visited[s] = true;
    } while (br != n);

    vertices[ogs] = 0;
    for (int i = 0; i < n; i++) cout << vertices[i] << ' ';

    return 0;

}
