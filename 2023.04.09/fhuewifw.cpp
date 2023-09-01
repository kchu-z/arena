#include <bits/stdc++.h>
using namespace std;

vector <int> vertices(100001);
vector <pair <int, int>> edges[100001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, br = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c = d - c;

        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
    }

    int s = 1;
    priority_queue <pair <int, int>> pq;
    set <int> visited;

    for (auto p : edges[s]) {
        pq.push({-(vertices[s] + p.first), p.second});
    }

    visited.insert(s);

    while (pq.size()) {
        while (pq.size() && visited.find(pq.top().second) != visited.end()) pq.pop();
        if (pq.empty()) break;

        auto p = pq.top();
        pq.pop();

        vertices[p.second] = -p.first;
        visited.insert(p.second);

        s = p.second;

        for (auto p : edges[s]) {
            pq.push({-(vertices[s] + p.first), p.second});
        }
    }

    cout << k - vertices[n] << endl;

    return 0;

}

