#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;
    unordered_map <int, int> v;
    unordered_map <int, bool> a;
    vector <int> s;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v[num]++;
        if (v[num] < 3) s.push_back(num);
    }

    for (int i : s) {
        if (!a[i]) {
            if (v[i] > 2) a[i] = true;
            cout << i << ' ';
        }
    }

    return 0;

}
