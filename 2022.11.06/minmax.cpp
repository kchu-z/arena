#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, st = 0;
    long long s;
    cin >> n >> s;
    vector <int> a(n);
    vector <pair <long long, long long> > v;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (i == n - 1 || a[i] != a[i + 1]) {
            v.push_back({a[i], i - st + 1});
            st = i + 1;
        }
    }

    int l = 0, r = v.size() - 1;

    while (l < r) {
        if (v[l].second < v[r].second) {
            if (s >= (v[l + 1].first - v[l].first) * v[l].second) {
                v[l + 1].second += v[l].second;
                s -= (v[l + 1].first - v[l].first) * v[l].second;
                l++;
            } else {
                v[l].first += s / v[l].second;
                break;
            }
        } else {
            if (s >= -(v[r - 1].first - v[r].first) * v[r].second) {
                v[r - 1].second += v[r].second;
                s -= -(v[r - 1].first - v[r].first) * v[r].second;
                r--;
            } else {
                v[r].first -= s / v[r].second;
                break;
            }
        }
    }

    cout << v[r].first - v[l].first << endl;

    return 0;
}
