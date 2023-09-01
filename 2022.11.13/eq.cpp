#include <bits/stdc++.h>
using namespace std;

char getDigit(int sum) {
    if (sum < 9) return sum + '0';
    else return sum - 10 + 'A';
}

int getDigit(char s) {
    if (s >= 'A') return s - 'A' + 10;
    else return s - '0';
}

string add(string a, string b, int base) {
    bool pr = false;

    string n;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < max(a.size(), b.size()); i++) {
        char A = '0';
        char B = '0';

        if (i < a.size()) A = a[i];
        if (i < b.size()) B = b[i];

        int sum = getDigit(A) + getDigit(B) + (int) pr;
        if (sum >= base) {pr = true;sum-=base;}
        else pr = false;

        n.push_back(getDigit(sum));
    }

    if (pr) n.push_back('1');
    reverse(n.begin(), n.end());

    return n;
}

int main() {

    string a, b, c;
    getline(cin, a, '+');
    getline(cin, b, '=');
    cin >> c;

    char maxChar = '0';
    for (char& i : a) maxChar = max(maxChar, i);
    for (char& i : b) maxChar = max(maxChar, i);
    for (char& i : c) maxChar = max(maxChar, i);

    for (int i = 2; i <= 37; i++) {
        string s = add(a, b, i);
        if (s == c) {
            cout << i << endl;
            return 0;
        }
    }

    cout << a << endl << b << endl << c << endl;

    return 0;

}
