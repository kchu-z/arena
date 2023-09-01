#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, k;
    cin >> n >> k;

    if (k % 2 != 0) {
        long long sum = (n + (k - 1) / 2);
        sum *= sum;
        sum -= n - 1;

        cout << sum << endl;
    } else {
        k--;
        long long sum = (n + (k - 1) / 2);
        sum *= sum;
        sum -= n - 1;
        sum += 2 * n - 1;

        cout << sum << endl;
    }

    return 0;

}
