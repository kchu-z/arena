#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, h, br = 0;
    cin >> n >> q;

    stack <pair <int, int>> height, ropes;

    for (int i = 0; i < n; i++) {
        cin >> h;

        if (!height.empty() && height.top().second == h) {
            pair <int, int> rope = {height.top().first, i};
            br++;

            if (ropes.empty() || rope.first >= ropes.top().second) ropes.push(rope);
        }

        while (!height.empty() && height.top().second < h) height.pop();
        height.push({i, h});
    }

    //if (q == 2) br -= ropes.size();
    cout << br << endl;

    return 0;

}
