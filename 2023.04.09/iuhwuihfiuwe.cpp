#include <bits/stdc++.h>
using namespace std;

long long a[100];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, maxn = 0;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;


        for (int sign = -1; sign <= 1; sign += 2) {
            long long num = 0;

            for (int j = 0; j < n; j++) {
                num = num * 10 + a[((i + sign * j) % n + n) % n];
            }

            maxn = max(maxn, num);
        }
    }

    cout << maxn << endl;
    return 0;

}
