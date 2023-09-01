#include <bits/stdc++.h>
using namespace std;

string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string from10(long long n, int base) {
    if (n == 0) return 0;
    string s;

    while (n) {
        s.push_back(ch[n % base]);
        n /= base;
    }

    reverse(s.begin(), s.end());
    return s;
}

int getNum(char s) {
    if (isdigit(s)) return s - '0';
    return s - 'A' + 10;
}

long long to10(string s, int base) {
    long long n = 0;

    for (char& i : s) n = n * base + getNum(i);

    //cout << s << ' ' << n;
    return n;
}

string tr(string s, int a, int b) {
    return from10(to10(s, a), b);
}

int main() {

    string a, b, c;
    getline(cin, a, '+');
    getline(cin, b, '=');
    cin >> c;

    char mx = 0;

    for (char& i : (a + b + c)) mx = max(mx, i);
    if (isdigit(mx)) mx -= '0';
    else mx -= 'A' - 10;

    for (int i = mx + 1; i <= 36; i++) {
        if (to10(a, i) + to10(b, i) == to10(c, i)) {
            cout << i;
            return 0;
        }
    }



    return 0;

}
