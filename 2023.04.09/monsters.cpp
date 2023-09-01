#include <bits/stdc++.h>
using namespace std;

long long a[1000000], sol[1000000];
deque <pair <long long, int>> q;

void print() {
    int sz = q.size();

    for (int i = 0; i < sz; i++) {
        auto p = q.front();
        cout << q.front().first << ' ' << q.front().second << ' ' << ' ';
        q.pop_front();
        q.push_back(p);
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, range = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }

    for (int i = n - 1; i >= 0; i--) {
        q.push_back({a[i], i});
        int last = n;
        cout << i << endl;

        while (q.size() && q.front().first + i > 0) {
            last = q.front().second;
            q.pop_front();
        }

        sol[i] = last;

        if (last != n) q.push_front({a[last], last});
        print();
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << sol[i] - i << ' ';
    }

    return 0;

}
