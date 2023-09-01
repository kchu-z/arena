#include <bits/stdc++.h>
using namespace std;
vector <string> v(1000000), s(1000000);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <string> v(n), s(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int sum = 0;
        for (char& j : v[i]) sum += j - '0';
        s[i] = sum;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[i] > s[j]) {
                swap(s[i], s[j]);
                swap(v[i], v[j]);
            } else if (v[i].size() > v[j].size()) {
                swap(s[i], s[j]);
                swap(v[i], v[j]);
            } else if (v[i] > v[j]) {
                swap(s[i], s[j]);
                swap(v[i], v[j]);
            }
        }
    }

    for (string i : v) cout << i << ' ';

    return 0;

}
