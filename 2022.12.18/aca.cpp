#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, mx = 0;
    cin >> n >> m >> k;

    vector <pair <int, int>> v;
    pair <int, int> pos;

    for (int i = 0; i < k; i++) {
        cin >> pos.first >> pos.second;
        pos.first--;
        pos.second--;


        v.push_back(pos);
    }

    for (int i = 0; i < v.size(); i++) {
        pair <int, int> pos1 = v[i];

        for (int j = i + 1; j < v.size(); j++) {
            pair <int, int> pos2 = v[j];

            if (pos1.first == pos2.first) {
                mx = max(mx, (abs(pos1.second - pos2.second) + 1) * max(pos1.first + 1, (int) v.size() - pos1.first));
            } else if (pos1.second == pos2.second) {
                mx = max(mx, (abs(pos1.first - pos2.first) + 1) * max(pos1.second + 1, (int) v.size() - pos1.second));
            } else {
                mx = max(mx, (abs(pos1.first - pos2.first) + 1) * (abs(pos1.second - pos2.second) + 1));
            }
        }
    }

    cout << mx << endl;
    return 0;

}
