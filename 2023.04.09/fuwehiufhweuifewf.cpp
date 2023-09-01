#include <bits/stdc++.h>
using namespace std;

int A, B, C;
string a, b, c;

int ex(string s) {
    if (s == "0") return 0;
    int x = 0;

    for (char cs : s) {
        x *= 10;

        if (cs == 'A') x += A;
        else if (cs == 'B') x += B;
        else if (cs == 'C') x += C;
        else x += cs - '0';
    }

    return x;
}

bool check() {
    return (ex(a) + ex(b) == ex(c))
    && (ceil(log10(ex(a) + 1)) == a.size() || ex(a) == 0)
    && (ceil(log10(ex(b) + 1)) == b.size() || ex(b) == 0)
    && (ceil(log10(ex(c) + 1)) == c.size() || ex(c) == 0);
}

int main() {


    getline(cin, a, '+');
    getline(cin, b, '=');
    getline(cin, c);

    if (a == "0") a = "";
    if (b == "0") b = "";
    if (c == "0") c = "";

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int z = 0; z < 10; z++) {
                if (x == y || x == z || y == z) continue;

                A = x;
                B = y;
                C = z;

                if (check()) {
                    cout << to_string(ex(a)) + "+" + to_string(ex(b)) + "=" + to_string(ex(c));
                    return 0;
                }
            }
        }
    }



    return 0;

}
