#include <bits/stdc++.h>
using namespace std;

struct p{
    int first, second;
};

bool cmp(p a, p b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main() {

    int n, num, br = 0;
    cin >> n;
    vector <p> v;
    vector <int> s;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back({i - num, num});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        if (br == 2) s.push_back(v[i].second);

        if (i == n - 1 || v[i].first != v[i + 1].first) {
            br++;

            if (br == 3) {
                cout << s.size();
                for (int i : s) cout << ' ' << i;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;

}
