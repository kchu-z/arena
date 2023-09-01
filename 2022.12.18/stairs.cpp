#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q, h, br = 0;
    cin >> n >> q;

    stack <pair <int, int>> heights, ropes;

    for (int i = 1; i <= n; i++) {
        cin >> h;
        while (!heights.empty() && heights.top().second < h) heights.pop();

        if (!heights.empty() && heights.top().second == h) {
            pair <int, int> rope = {heights.top().first, i};

            if (ropes.empty() || rope.first >= ropes.top().second) ropes.push(rope);
            br++;
        }

        heights.push({i, h});
    }

    if (q == 1) cout << br << endl;
    else cout << br - ropes.size() << endl;

    return 0;

}
