#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp) {
    if (exp == 0) return 1;

    if (exp % 2 == 0) {
        long long x = power(base, exp / 2);
        return x * x;
    }

    return base * power(base, exp - 1);
}

int main() {

    long long n;
    cin >> n;

    long long digits = to_string(n).size(), ans = 0;

    for (int i = 1; i < digits; i++) {
        ans += power(10, (i - 1) / 2) * 9;
    }

    string N = to_string(n);
    long long first = stoi(N.substr(0, (N.size() - 1) / 2 + 1));
    string Second = N.substr((N.size()) / 2, -1);
    reverse(Second.begin(), Second.end());
    long long second = stoi(Second);

    //cout << first << ' ' << second << endl;
    //cout << power(10, (N.size() - 1) / 2) << endl;
    //cout << min(first, second) << endl;
    ans += first - power(10, (N.size() - 1) / 2) + (int) (first <= second);

    cout << ans << endl;
    return 0;

}
