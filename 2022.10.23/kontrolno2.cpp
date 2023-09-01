#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;
    unordered_map <int, bool> a, b, c;
    vector <int> v;

    for (int i = 0; i < n; i++) {
        cin >> num;
        a[num] = true;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (a[num]) b[num] = true;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (b[num]) v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i : v) cout << i << ' ';

    return 0;

}

