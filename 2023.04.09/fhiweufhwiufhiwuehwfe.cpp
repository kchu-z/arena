#include <bits/stdc++.h>
using namespace std;

vector <long long> vertices(100001), r(200001), g(200001);
vector <pair <long long, pair <int, int>>> edges[200001];

long long ex(long long t, long long idx) {
    t %= (r[idx] + g[idx]);

    if (t < g[idx]) return 0;
    return r[idx] + g[idx] - t;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m, S;
    cin >> n >> m >> S;

    for (int i = 0; i < m; i++) {
        long long a, b, s;
        cin >> a >> b >> s >> g[i] >> r[i];

        edges[a].push_back({s, {b ,i}});
        edges[b].push_back({s, {a, i}});
    }

    long long s = 1;
    priority_queue <pair <long long, long long>> pq;

    vertices[s] = S;

    for (auto p : edges[s]) {
        pq.push({-(vertices[s] + p.first + ex(vertices[s], p.second.second)), p.second.first});
    }

    while (pq.size()) {
        if (pq.empty()) break;

        auto p = pq.top();
        pq.pop();

        if (!vertices[p.second]) vertices[p.second] = -p.first;
        else continue;

        s = p.second;

        for (auto p : edges[s]) {
            pq.push({-(vertices[s] + p.first + ex(vertices[s], p.second.second)), p.second.first});
        }

        //cout << s << ' ' << vertices[s] << endl;
    }

    for (long long i = 2; i <= n; i++) {
        cout << vertices[i] << ' ';
    }

    return 0;

}
