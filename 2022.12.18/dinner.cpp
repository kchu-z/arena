#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    vector <pair <long long, long long>> v(n); /// -v.first, -v.second
    vector <long long> prefix(n);

    for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());

    prefix[n - 1] = v[n - 1].second;
    for (int i = n - 2; i >= 0; i--) prefix[i] = min(v[i].second, prefix[i + 1]);

    long long sum = 0, meal = -LLONG_MIN;

    for (int i = 0; i < n; i++) {
        meal = max(meal, v[i].first - v[i].second);

        long long ans1 = sum + prefix[i], ans2 = sum + v[i].first - meal;
        sum += v[i].first;

        cout << min(ans1, ans2) << '\n';
    }

    return 0;

}
