#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector <pair <long long, long long>> runners_pos(k), pos(n);

    vector <double> s(k);

    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> pos[i].first >> pos[i].second;
        runners_pos[i] = pos[i];
    }

    for (int i = k; i < n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    for (auto& i : runners_pos) {
        cout << i.first << ' ' << i.second << endl;
    }

    for (int i = 1; i <= k; i++) {
        cout << i << endl;
    }

    for (int i = k; i < n; i++) {
        double mn = ULLONG_MAX;
        int idx;

        for (int j = 0; j < k; j++) {
            double p = (pos[i].first - runners_pos[j].first) * (pos[i].first - runners_pos[j].first) + (pos[i].second - runners_pos[j].second) * (pos[i].second - runners_pos[j].second);
            double dur = p * s[j];

            if (mn > dur) {
                mn = dur;
                idx = j;
            }
        }

        cout << idx << endl;
        runners_pos[idx] = pos[i];
    }

    return 0;

}
