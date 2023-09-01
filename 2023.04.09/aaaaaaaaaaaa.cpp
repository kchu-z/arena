#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, br = 0, mx = 0;
    cin >> n;
    vector <pair <long long, long long> > v, ans;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == -1) {
            if (ans.back().second == -1) {
                ans.back() = {ans.back().first, v[i].first - 1};
                //cout << ans.back().first << ' ' << v[i].first - 1 << endl;
            }

            br--;
        } else if (v[i].second == 1) {
            br++;

            if (mx < br) {
                mx = br;
                ans.clear();

                ans.push_back({v[i].first, -1});
                //cout << v[i].first << endl;
            } else if (mx == br) {
                if (ans.back().second == -1) continue;
                if (v[i].first <= ans.back().second) ans.back() = {ans.back().first, -1};
                else ans.push_back({v[i].first, -1});
            }
        }

        //cout << "p." << v[i].first << " : " << br << endl;
    }

    long long sum = 0;

    //cout << endl;
    for (auto p : ans) {
        sum += p.second - p.first + 2;
        //cout << p.first << ' ' << p.second + 1 << endl;
    }

    cout << sum << endl;
    return 0;

}
/**

10
1 2
2 3
3 4
4 5
5 7
2 5
5 7
1 3
4 5
5 7

*/
