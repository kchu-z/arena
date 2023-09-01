#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, num;
    cin >> m >> n;
    unordered_map <int, int> v;
    vector <int> s;

    for (int i = 0; i < m; i++) {
        cin >> num;
        v[num]++;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        v[num]--;
    }

    for (auto& it : v) {
        for (int i = 0; i < it.second; i++) s.push_back(it.first);
    }

    sort(s.begin(), s.end());

    for (int i : s) cout << i << ' ';

    return 0;

}
