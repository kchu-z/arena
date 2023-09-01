#include <bits/stdc++.h>
using namespace std;

struct p{
    string first, second;
};

bool cmp(p a, p b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <p> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;

}
