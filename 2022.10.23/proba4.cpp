#include <bits/stdc++.h>
using namespace std;

int main() {

    string num;
    char s1, s2;

    for (int i = 1; i <= 2016; i++) {
        num += to_string(i);
    }

    cout << num << endl;

    s1 = num[2015];
    reverse(num.begin(), num.end());
    s2 = num[2015];

    cout << s1 << ' ' << s2 << ' ' << s1 - s2;

    return 0;

}
