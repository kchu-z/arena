#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> points(21);
int n, m, x, y, k;

unsigned long long d(int a, int b) {
    return abs(points[a].first - points[b].first) + abs(points[a].second - points[b].second);
}

unsigned long long f(unsigned long long state, int last) {
    if (state == 1 && last == 0) return 1;
    unsigned long long ans = INT_MAX;

    for (int i = 0; i < k + 2; i++) {
        if (i == last) continue;
        if (state & (1 << i) == 0) continue;

        ans = min(ans, f(state ^ (1 << last), i) + d(i, last));
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> points[0].first >> points[0].second >> k;

    for (int i = 1; i <= k; i++) {
        cin >> points[i].first >> points[i].second;
    }
    points[k+1] = points[0];

    cout << f((1 << (k+2)) - 1, 0);
    return 0;

}
