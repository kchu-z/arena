#include <bits/stdc++.h>
using namespace std;

struct p{
    int first, second;
};

bool cmp(p a, p b) {
    if (a.second - a.first != b.second - b.first) return a.second - a.first < b.second - b.first;
    return a.first < b.first;
}

int main() {

    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    vector <p> s;

    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            s.push_back({v[i], v[j]});
        }
    }

    sort(s.begin(), s.end(), cmp);

    cout << s[k - 1].first << ' ' << s[k - 1].second;

    return 0;

}
