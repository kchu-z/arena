#include <bits/stdc++.h>
using namespace std;

long long visited[1000001];
long long a[1000001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    long long s;
    cin >> s;

    pair <long long, long long> p = {INT_MAX, INT_MAX};

    for (int i = 1; i <= n; i++) {
        long long x = a[i];
        if (!visited[x]) visited[x] = i;

        if (visited[s - x]) {
            //cout << visited[s - x] << ' ' << i << '\n';
            p = min(p, {s - x, i});
            //return 0;
        }
    }

    if (p.first == INT_MAX) p = {0, 0};
    cout << p.first << ' ' << p.second << endl;
    return 0;

}
