#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {

    freopen("runners.in", "r", stdin);
    freopen("runners.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k, x, y;
    cin >> n >> k;
    vector <pair <double, int>> runners_speed(k);

    for (int i = 0; i < k; i++) { /// O(k)
        cin >> runners_speed[i].first;
        runners_speed[i].second = i;
    }

    vector <pair <long long, long long>> computers_position(n), runners_position(k);
    vector <int> counter(n, 1), pointer_array(n);

    for (int i = 0; i < n; i++) { /// O(n)
        cin >> computers_position[i].first >> computers_position[i].second;
    }

    for (int i = 0; i < k; i++) {
        runners_position[i] = computers_position[i];
    }

    for (int i = k; i < n; i++) { /// O(nk)
        long long time = LLONG_MAX;
        int idx;

        x = computers_position[i].first;
        y = computers_position[i].second;

        for (int j = 0; j < k; j++) {
            pair <long long, long long> pos = runners_position[j];
            long long newTime = (x - pos.first) * (x - pos.first) + (y - pos.second) * (y - pos.second);

            if (time > newTime) {
                time = newTime;
                idx = j;
            }
        }

        pointer_array[i] = idx;
        counter[idx]++;
        runners_position[idx] = computers_position[i];

        ///cout << idx + 1<< endl;
    }

    ///cout << endl;

    for (int i = 0; i < k; i++) {
        ///cout << counter[i] << endl;
    }

    vector <pair <int, int>> computers_counter(k);

    for (int i = 0; i < k; i++) {
        computers_counter[i] = {counter[i], i};
    }

    sort(runners_speed.begin(), runners_speed.end()); /// 2 mil
    sort(computers_counter.begin(), computers_counter.end()); /// 2 mil

    vector <int> computers_pointer(k), runners_pointer(k);

    for (int i = 0; i < k; i++) {
        pointer_array[computers_counter[i].second] = runners_speed[i].second;
        runners_pointer[runners_speed[i].second] = computers_counter[i].second;
    }

    for (int i = 0; i < k; i++) {
        pair <int, int> pos = computers_position[runners_pointer[i]];
        cout << pos.first << ' ' << pos.second << endl;
    }

    for (int i = 0; i < k; i++) {
        cout << pointer_array[i] + 1 << endl;
    }

    for (int i = k; i < n; i++) {
        cout << pointer_array[pointer_array[i]] + 1 << endl;
    }


    return 0;

}
/// 5 2 1.3 1.8 3 8 6 7 9 4 10 2 1 5
