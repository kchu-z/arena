#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, num, ins = 0, del = 0;
    cin >> n;

    deque <pair <int, int>> v;

    for (int i = 0; i < n; i++) {
        cin >> t;

        if (t == 1) {
            cin >> num;

            while (!v.empty() && v.back().first < num) v.pop_back();
            v.push_back({num, ins});

            ins++;
        } else {
            if (v.front().second == del) v.pop_front();
            del++;
        }

        if (v.empty()) cout << -1 << ' ';
        else cout << v.front().first << ' ';
    }

    return 0;

}
