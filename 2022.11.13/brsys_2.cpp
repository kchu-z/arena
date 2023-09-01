#include <bits/stdc++.h>
using namespace std;

string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getChar(char s) {
    if (isdigit(s)) return s - '0';
    return s - 'A' + 10;
}

long long to(string s, int p) {
    long long n = 0;

    for (char& i : s) {
        n = n * p + getChar(i);
    }

    return n;
}

string from(long long n, int p) {
    if (n == 0) return "0";
    string s;

    while (n) {
        s.push_back(chars[n % p]);
        n /= p;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long p;
    long long s;
    cin >> p >> s;

    cout << from(s, p);

    return 0;

}
