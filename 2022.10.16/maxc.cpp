#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b) {
    string s1 = a, s2 = b;
    s1 += b;
    s2 += a;

    return s1 > s2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <string> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }

    return 0;

}

// 9 5 50 55 57 505 506 59 6 575
// 6 59 57 575 5 55 506 505 50
// 6 59 57 575 5 55 506 50 505
