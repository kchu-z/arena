#include <bits/stdc++.h>
using namespace std;

long long a[1000000], sol[1000000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, last = -1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = last + 1; j < min(n, i + 1) && j > i - a[i]; j++) {
            sol[j] = i;
        }

        last = i - a[i];
    }

    for (int i = last; i < n; i++) sol[i] = n;

    for (int i = 0; i < n; i++) {
        cout << sol[i] - i << endl;
    }

    return 0;

}
