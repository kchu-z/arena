#include <bits/stdc++.h>
using namespace std;

vector <int> edges[1001];
int n, m, a, b;
int da[1001], db[1001];

queue <int> q;

void pusha(int from, int to) {
    if (da[to]) return;
    da[to] = da[from] + 1;

    q.push(to);
}

void solvea() {
    q.push(a);
    da[a] = 1;

    while (q.size()) {
        auto pos = q.front();
        q.pop();

        for (int x : edges[pos]) {
            pusha(pos, x);
        }
    }

    while (q.size()) q.pop();
}

void pushb(int from, int to) {
    if (db[to]) return;
    db[to] = db[from] + 1;

    q.push(to);
}

void solveb() {
    q.push(b);
    db[b] = 1;

    while (q.size()) {
        auto pos = q.front();
        q.pop();

        for (int x : edges[pos]) {
            pushb(pos, x);
        }
    }

    while (q.size()) q.pop();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int query = 0; query < 2; query++) {
        cin >> a >> b;
        solvea();
        solveb();

        int distance = da[b] - 1, br = n;

        for (int i = 1; i <= n; i++) {
            if (da[i] + db[i] - 2 == distance) br--;
            //cout << db[i] << endl;
        }

        cout << br << ' ';

        for (int i = 1; i <= n; i++) {
            da[i] = 0;
            db[i] = 0;
        }
    }



    return 0;

}
