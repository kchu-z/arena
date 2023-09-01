#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> nums;

void ex(vector <int> v) {
    int n = v.size();
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (i + 1 == n || v[i] != v[i + 1]) {
            nums[v[i]]++;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <int> v(n);

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < n; i++) cin >> v[i];
        ex(v);
    }

    vector <int> s;

    for (auto p : nums) {
        if (p.second == 3) s.push_back(p.first);
    }

    sort(s.begin(), s.end());
    for (int x : s) cout << x << ' ';

    return 0;

}
