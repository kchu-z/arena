#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    bool f = false;

    if (a.size() > b.size()) {
        swap(a, b);
        f = true;
    }

    for (int i = 0; i < b.size(); i++) {
        char s1 = a[i % (int) a.size()], s2 = b[i];
        if (s1 != s2) {
            if (!f) return s1 < s2;
            else return s1 > s2;
        }
    }

    return false;
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
