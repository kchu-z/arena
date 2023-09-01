#include <bits/stdc++.h>
using namespace std;

int a[200001], n;
vector <int> edges[200001];

int visited_odd[200001], visited_even[200001];
queue <int> q;

void push_odd(int from, int to) {
    if (visited_odd[to]) return;
    visited_odd[to] = visited_odd[from] + 1;

    q.push(to);
}

void push_even(int from, int to) {
    if (visited_even[to]) return;
    visited_even[to] = visited_even[from] + 1;

    q.push(to);
}

void solve_odd() {
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 != 0) {
            visited_odd[i] = 1;
            q.push(i);
        }
    }

    while (q.size()) {
        auto pos = q.front();
        q.pop();

        for (int x : edges[pos]) {
            push_odd(pos, x);
        }
    }

    while (q.size()) q.pop();
}

void solve_even() {
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            visited_even[i] = 1;
            q.push(i);
        }
    }

    while (q.size()) {
        auto pos = q.front();
        q.pop();

        for (int x : edges[pos]) {
            push_even(pos, x);
        }
    }

    while (q.size()) q.pop();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (1 <= i - a[i]) edges[i - a[i]].push_back(i);
        if (i + a[i] <= n) edges[i + a[i]].push_back(i);
    }

    solve_odd();
    solve_even();

    for (int i = 1; i <= n; i++) {
        if (a[i] % 2) cout << visited_even[i] - 1 << ' ';
        else cout << visited_odd[i] - 1 << ' ';
    }

    return 0;

}
