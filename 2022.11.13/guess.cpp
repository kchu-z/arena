#include <bits/stdc++.h>
using namespace std;

int main() {

    string a, b, c;
    int i;

    getline(cin, a, '=');
    cin >> c;

    for (i = 1; i < a.size(); i++) {
        if (!isdigit(a[i]) && a[i] != '?') break;
    }

    b = a.substr(i + 1, -1);
    char sym = a[i];
    a = a.substr(0, i);

    vector <bool> digits(10);

    //for (char i : (a + b + c)) {
    //    if (isdigit(i)) digits[i - '0'] = true;
    //}

    //if (a[0] == '?' || b[0] == '?' || c[0] == '?') i = 1;
    //else i = 0;

    for (i = 0; i < 10; i++) {


        string A = a, B = b, C = c;
        for (char& j : A) if (j == '?') j = i + '0';
        for (char& j : B) if (j == '?') j = i + '0';
        for (char& j : C) if (j == '?') j = i + '0';

        long long x = stoi(A);
        long long y = stoi(B);
        long long z = stoi(C);

        if (sym == '+') {
            if (x + y == z) {cout << i; return 0;}
        } else if (sym == '-') {
            if (x - y == z) {cout << i; return 0;}
        } else if (sym == '*') {
            if (x == 1 || y == 1 || x == 0 || y == 0) continue;
            if (x * y == z) {cout << i; return 0;}
        } else {
            if (z * y == x) {cout << i; return 0;}
        }
    }

    cout << "mistake";

    return 0;

}
