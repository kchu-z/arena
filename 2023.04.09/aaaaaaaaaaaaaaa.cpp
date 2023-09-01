#include <bits/stdc++.h>
using namespace std;

string chars = "0123456789ABCDEF";

string from10(unsigned long long n, unsigned long long p) {
    string ans;

    while (n) {
        ans.push_back(chars[n % p]);
        n /= p;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n, p, sum = 0, base = 1, br;
    cin >> p >> n;

    for (br = 1; n > sum; br++) {
        n -= sum;

        sum = br * base * (p - 1);
        base *= p;

    }

    br--;
    n--;

    unsigned long long number = base / p + n / br;
    unsigned long long digit = (n + br) % br;

    //cout << n << ' ' << number << ' ' << digit << endl;
    cout << from10(number, p)[digit] << endl;

    return 0;

}
