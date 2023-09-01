#include <bits/stdc++.h>
using namespace std;

int ost[] = {1, 2, 4};

int main() {

    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    int br = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') br += ost[i % 3];
    }

    if (br % 7 == 0) cout << "YES";
    else cout << 7 - br % 7;


    return 0;

}
