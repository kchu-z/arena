#include <bits/stdc++.h>
using namespace std;

int main() {

    vector <vector <int>> v(721);

    long long a, b, work_time = 0, wait_time = 0, price = 0;

    while (cin >> a >> b) {
        v[a].push_back(b);
    }

    for (int i = 0; i <= 720; i++) {
        sort(v[i].begin(), v[i].end());
    }

    for (int time = 0; time <= 720; time++) {
        if (v[time].empty()) continue;

        if (work_time < time) {
            wait_time += time - work_time;
            work_time = time;
        }

        for (int k : v[time]) {
            price += work_time - time;
            work_time += k;

            //cout << time << ' ' << k << ' ' << price << endl;
        }
    }

    if (work_time < 720) wait_time += 720 - work_time;
    cout << wait_time << ' ' << price << endl;

    return 0;

}
