#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int sum = 0;

    string s;
    cin >> s;

    for (char& i : s) sum += i - '0';

    cout << ((s.back() - '0') % 2 == 0) << ' ' << (sum % 3 == 0) << ' ' << ((s.back() - '0') % 5 == 0);

    return 0;

}
