#include <bits/stdc++.h>
using namespace std;

long long digitsToN(long long n) {
    long long maxDigits = to_string(n).size(), maxNumber = 1, ans = 0;

    for (int digits = 1; digits < maxDigits; digits++) {
        ans += 9 * maxNumber * digits;
        maxNumber *= 10;
    }

    ans += (n - maxNumber + 1) * maxDigits;
    return ans;
}

long long solve(long long mx, long long n) {
    long long halfDigits = digitsToN(mx);
    bool rev = false;

    if (n <= halfDigits) {
        /// left
        n = halfDigits - n + 1;
        rev = true;
    } else {
        /// right
        n -= halfDigits - 1;
    }

    long long minNum = 1, digits = 1;

    for (digits; true; digits++) {
        int brDigits = minNum * 9 * digits;

        if (n <= brDigits) {
            //cout << n << ' ' << minNum << endl;
            break;
        }

        n -= brDigits;
        minNum *= 10;
    }

    long long num = (n + digits - 1) / digits;
    n -= (num - 1) * digits;
    num += minNum - 1;
    //cout << n << ' ' << num << endl;
    string chislo = to_string(num);
    if (rev) reverse(chislo.begin(), chislo.end());

    return (int) (chislo[n - 1] - '0');

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, a, b;
    cin >> n >> a >> b;

    cout << solve(n, a) - solve(n, b);
    //cout << digitsToN(n);

    return 0;

}
