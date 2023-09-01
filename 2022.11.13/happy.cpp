#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n) {
    string s = to_string(n);
    vector <int> v(10);

    bool f = false, h = false;

    for (char& i : s) v[i - '0']++;
    for (int i : v) {
        if (i == 2) {
            if (f) h = false;
            else {
                f = true;
                h = true;
            }
        }
    }

    return h;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;

    vector <int> a, b;
    int mn = INT_MAX, idx;

    for (int i = 0; i < n; i++) {
        cin >> num;

        if (isHappy(num)) a.push_back(num);
        else b.push_back(num);
    }

    for (int i : a) {
        for (int j : b) {
            if (mn > abs(i - j)) {
                mn = abs(i - j);
                idx = j;
            }
        }
    }

    if (mn == INT_MAX) cout << 0;
    else cout << idx;

    return 0;

}
