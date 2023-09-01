#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    vector <int> v(256);

    int br = 0;

    for (char& i : s) v[i]++;
    for (int i : v) {
        if (i % 2 == 1) br++;
    }

    if (br == 0) br++;
    cout << br;

    return 0;

}
