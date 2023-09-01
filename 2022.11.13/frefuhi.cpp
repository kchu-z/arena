#include <bits/stdc++.h>
using namespace std;

string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getChar(char s) {
    if (isdigit(s)) return s - '0';
    return s - 'A' + 10;
}

string add(string a, string b, int p) {
    string s;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int pr = 0;

    for (int i = 0; i < max(a.size(), b.size()) || pr; i++) {
        int sum = pr;
        if (i < a.size()) sum += getChar(a[i]);
        if (i < b.size()) sum += getChar(b[i]);

        pr = sum / p;
        s.push_back(ch[sum % p]);
    }

    reverse(s.begin(), s.end());
    return s;
}

int main() {

    int p;
    string a, b;
    cin >> p >> a >> b;

    cout << add(a, b, p);

}
