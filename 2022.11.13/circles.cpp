#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a, b;
    char c;
    cin >> a >> b >> c;

    if (c == '+') a += b;
    else if (c == '-') a = abs(a - b);
    else if (c == '*') a *= b;

    string s = to_string(a);
    int zero[] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1}, br = 0;

    for (char& i : s) br += zero[i - '0'];

    cout << br;

    return 0;

}
