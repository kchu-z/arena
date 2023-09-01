#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;
    unordered_map <int, bool> a, b, c;
    unordered_map <int, int> v;
    vector <int> s;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (a[num] == false) {
            a[num] = true;
            v[num]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (b[num] == false) {
            b[num] = true;
            v[num]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (c[num] == false) {
            c[num] = true;
            v[num]++;
        }
    }

    for (auto i : v) {
        if (i.second == 3) s.push_back(i.first);
    }

    sort(s.begin(), s.end());

    for (int i : s) cout << i << ' ';

    return 0;

}

