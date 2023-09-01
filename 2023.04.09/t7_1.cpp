#include <bits/stdc++.h>
using namespace std;

long long a[1000001], prefix[1000001];
long long n, k;

bool check(long long l, long long r) {
    return (prefix[r] / prefix[l - 1]) % k != 0;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long long br = 0;
    prefix[0] = 1;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = (prefix[i - 1] * a[i]);
    }

    long long j = 0;

    for (long long i = 1; i <= n; i++) {
        while (j < n && check(i, j + 1)) j++;

        br += n - j;

        if (j < i) j = i;
    }

    cout << br << endl;
    return 0;

}
