#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector <int> edges[100001];

int visited_a[100001], visited_b[100001], visited_c[100001], visited_d[100001];
bool valid_vertices[100001];

int main() {

    int n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    queue <int> q;

    q.push(a);
    visited_a[a] = 1;

    while (q.size()) {
        auto pos = q.front();
        q.pop();

        for (int x : edges[pos]) {
            if (visited_a[x]) continue;
            visited_a[x] = visited_a[pos] + 1;

            q.push(x);
        }
    }

    q.push(b);
    visited_b[b] = 1;


    while (q.size()) {
        auto pos = q.front();
        q.pop();

        for (int x : edges[pos]) {
            if (visited_b[x]) continue;
            visited_b[x] = visited_b[pos] + 1;

            q.push(x);
        }
    }

    q.push(c);
    visited_c[c] = 1;


    while (q.size()) {
        auto pos = q.front();
        q.pop();

        for (int x : edges[pos]) {
            if (visited_c[x]) continue;
            visited_c[x] = visited_c[pos] + 1;

            q.push(x);
        }
    }

    q.push(d);
    visited_d[d] = 1;


    while (q.size()) {
        auto pos = q.front();
        q.pop();

        for (int x : edges[pos]) {
            if (visited_d[x]) continue;
            visited_d[x] = visited_d[pos] + 1;

            q.push(x);
        }
    }

    int first_distance = visited_a[b] - 1;
    int second_distance = visited_c[d] - 1;

    for (int i = 1; i <= n; i++) {
        ///cout << visited_a[i] - 1 << ' ' << visited_b[i] - 1 << ' ' << visited_c[i] - 1 << ' ' << visited_d[i] - 1 << endl;
        if (first_distance == visited_a[i] + visited_b[i] - 2 && second_distance == visited_c[i] + visited_d[i] - 2) {
            ///cout << i << endl;
            valid_vertices[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {

    }

    return 0;

}
/**
6 7
1 3 1 6
1 2
2 3
2 5
3 6
4 5
4 6
5 6
*/
