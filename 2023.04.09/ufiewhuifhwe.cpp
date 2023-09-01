#include <bits/stdc++.h>
using namespace std;

long long a[100000], b[100000];

unordered_map <long long, long long> largest;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m, k;
    cin >> n >> m >> k;

    set <long long> s;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    auto it = s.end();
    it--;

    largest[(*it)] = (*it);
    it--;

    for (it; it != s.begin(); it--) {
        auto next_it = it;
        next_it++;

        if (*next_it == (*it) + 1) largest[(*it)] = largest[(*next_it)];
        else largest[(*it)] = (*it);
    }

    auto next_it = it;
    next_it++;

    if (*next_it == (*it) + 1) largest[(*it)] = largest[(*next_it)];
    else largest[(*it)] = (*it);

    for (int i = 0; i < k; i++) {
        cin >> b[i];

        auto it = s.lower_bound(b[i]);

        if (it == s.end()) {
            cout << b[i] << ' ';
            continue;
        }

        if ((*it) != b[i]) {
            cout << b[i] << ' ';
            continue;
        }

        cout << largest[(*it)] + 1 << ' ';

        /**auto it2 = it;
        it2++;

        while (it2 != s.end() && (*(it2)) - 1 == (*it)) {
            it++;
            it2++;
        }

        cout << (*it) + 1 << ' ';*/
    }

    return 0;

}

/**
1000 5 3
15 20 21 31 30
1 20 31
*/

/**
1000 10
4
2 3 4 5 6 7 8 9 10 11
1 2 11 12
*/
