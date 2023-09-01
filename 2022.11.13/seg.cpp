#include <bits/stdc++.h>
using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first > b.first) swap(a, b);
    else if (a.second > b.second) swap(a, b);

    return a.first <= b.first && b.first <= a.second;
}

int main() {

    int n;
    cin >> n;
    vector <pair <int, int>> v(n);
    vector <int> br(n);

    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(v[i], v[j])) {
                br[i]++;
                br[j]++;
            }
        }
    }

    int c = 0;
    for (int i : br) c = max(c, i);

    cout << c << endl;

    return 0;

}

/// 5 1 4 3 6 2 5 1 2 6 7
