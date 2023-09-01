#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long x) {
    if (x == 0) return 1;
    return base * power(base, x - 1);
}

int main() {

    long long n, i = 1;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    } else if (n == 2) {
        cout << 6;
        return 0;
    }

    n -= 2;

    while (n - power(2, i) > 0) {
        n -= power(2, i);
        i++;
    }

    string str;
    n--;

    for (long long j = 0; j < i; j++) {
        long long x = (n / power(2, j)) % 2;
        if (x == 0) str.push_back('0');
        else str.push_back('6');
        //cout << x << endl;
    }

    str.push_back('6');
    reverse(str.begin(), str.end());
    cout << str << endl;

    //cout << i << ' ' << n;

    return 0;

}
