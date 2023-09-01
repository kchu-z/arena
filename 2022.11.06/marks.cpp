#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num, m, br = 0;
    cin >> n >> m;
    unordered_map <int, bool> v;
    vector <int> arr;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v[num] = true;
    }

    for (int i = 0; i < m; i++) {
        cin >> num;
        if (v[num]) {
            br++;
            arr.push_back(num);
        }
    }

    cout << br << endl;

    for (int i : arr) cout << i << ' ';

    return 0;

}
