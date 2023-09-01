#include <bits/stdc++.h>
using namespace std;

vector <int> v;

bool bs(int l, int r, int p) {
    if (l > r) return false;

    int m = (l + r) / 2;

    if (p == v[m]) return true;
    if (p < v[m]) return bs(l, m - 1, p);
    return bs(m + 1, r, p);
}

int main() {

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;

        if (bs(0, n - 1, num)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;

}
