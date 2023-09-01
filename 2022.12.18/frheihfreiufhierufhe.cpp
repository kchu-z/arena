#include <bits/stdc++.h>
using namespace std;

string check_without_0(string v, int k) {
    string s;

    while (v.size() > k) {
        int maxi = 0;

        for (int i = 1; i <= k; i++) {
            if (v[v.size() - i - 1] > v[v.size() - maxi - 1]) maxi = i;
        }

        for (int i = 0; i < maxi; i++) {
            v.pop_back();
            k--;
        }

        s.push_back(v.back());
        v.pop_back();
    }

    return s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, num;
    char s;

    cin >> n >> k;
    string a, b, c;

    for (int i = 0; i < n; i++) {
        cin >> s;
        a.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        b.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        c.push_back(s);
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());

    a = check_without_0(a, k);
    b = check_without_0(b, k);
    c = check_without_0(c, k);

    cout << a << b << c << endl;
    return 0;

}
