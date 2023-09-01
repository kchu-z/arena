#include <bits/stdc++.h>
using namespace std;

long long n, m, s, k;
vector <long long> edges[100001];
long long goods[100001];

long long visited_nodes[100001];
bool visited_goods[100001];
queue <long long> q;
vector <long long> visited_nodes_vector, visited_goods_vector;

void push(long long from, long long to) {
    if (visited_nodes[to]) return;
    visited_nodes[to] = visited_nodes[from] + 1;
    visited_nodes_vector.push_back(to);

    q.push(to);
}

void solve(long long start) {
    long long br = 0, sum = 0;
    q.push(start);
    visited_nodes[start] = 1;

    visited_nodes_vector.push_back(start);

    while (!q.empty() && br < s) {
        auto pos = q.front();
        q.pop();
        //cout << pos << ' ';


        if (!visited_goods[goods[pos]]) {
            br++;
            sum += visited_nodes[pos] - 1;
            visited_goods[goods[pos]] = 1;
            visited_goods_vector.push_back(goods[pos]);
        }

        for (long long x : edges[pos]) {
            push(pos, x);
        }
    }

    for (long long node : visited_nodes_vector) {
        visited_nodes[node] = 0;
    }

    for (long long good : visited_goods_vector) {
        visited_goods[good] = 0;
    }

    visited_nodes_vector.clear();
    visited_goods_vector.clear();
    while (q.size()) q.pop();

    cout << sum << ' ';
}

int main() {

    cin >> n >> m >> k >> s;

    for (long long i = 1; i <= n; i++) cin >> goods[i];

    for (long long i = 1; i <= m; i++) {
        long long u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (long long i = 1; i <= m; i++) solve(i);

    return 0;

}
