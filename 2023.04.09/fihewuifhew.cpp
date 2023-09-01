#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, mxbr = 0, br = 0;
    char previous, s;

    cin >> k;
    deque <pair <char, int>> q;

    for (int i = 1; cin >> s; i++) {

        while (q.size() && q.front().second + k <= i) q.pop_front();
        while (q.size() && q.back().first > s) q.pop_back();
        q.push_back({s, i});

        auto [current, index] = q.front();

        if (k == i) {
            br = 1;
            mxbr = 1;
        } else if (k < i) {
            if (previous == current) {
                br++;
                mxbr = max(mxbr, br);
            } else br = 1;
        }

        previous = current;
    }

    cout << mxbr << endl;
    return 0;
}
