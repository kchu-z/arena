#include <bits/stdc++.h>
using namespace std;

long long m, n, k;
unordered_map <long long, bool> v;

bool check(long long x, long long y) {
    long long z = n * (x - 1) + y;

    if (!v[z]) {
        v[z] = 1;
        return 1;
    }
    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long x, y, br = 0;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        long long x2 = m - x + 1, y2 = n - y + 1;

        br += check(x, y);
        br += check(x, y2);
        br += check(x2, y);
        br += check(x2, y2);
    }

    cout << br << endl;
    return 0;

}
/// 4 4 5 3 2 1 2 4 3 2 4 4 1
