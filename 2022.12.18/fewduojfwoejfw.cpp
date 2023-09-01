#include <bits/stdc++.h>
using namespace std;

int getDistance(pair <int, int> pos1, pair <int, int> pos2) {
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

int main() {

    int m, n, k, houseX, houseY, mx = 1000;
    cin >> m >> n >> houseX >> houseY >> k;

    vector <int> perm(k);
    vector <pair <int, int>> pos(k);

    for (int i = 0; i < k; i++) {
        cin >> pos[i].first >> pos[i].second;
        perm[i] = i;
    }

    do {
        pair <int, int> currentPos = {houseX, houseY};
        int br = 0;

        for (int goal : perm) {
            br += getDistance(currentPos, pos[goal]);
            currentPos = pos[goal];
        }

        br += getDistance(currentPos, {houseX, houseY});

        mx = min(mx, br);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << mx << endl;
    return 0;

}
/// 10 10 1 1 4 2 3 5 5 9 4 6 5
