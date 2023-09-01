#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string rraannddoomm;
    getline(cin, rraannddoomm);

    pair <string, int> majorant;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (majorant.second == 0) {
            majorant.first = s;
            majorant.second = 1;
            continue;
        }

        if (s == majorant.first) majorant.second++;
        else majorant.second--;
    }

    cout << majorant.first << endl;
    return 0;

}
