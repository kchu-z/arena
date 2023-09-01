#include <bits/stdc++.h>
using namespace std;

vector <int> v[100000];
vector <string> v2;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, br = 0, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v2.push_back(s);

        for (int j = 0; j < 10; j++) v[i].push_back(0);

        //for (char c : s) v[i][c - '0']++;
    }

    sort(v2.begin(), v2.end());

    for (int i = 0; i < n; i++) {
        if (i + 1 == n || v[i] != v[i + 1]) {
            for (char c : v2[i]) v[i][c - '0']++;
        }
    }

    sort(v, v + n);

    for (int i = 0; i < n; i++) {
        br++;

        if (i + 1 == n || v[i] != v[i + 1]) {
            ans += br * (br - 1) / 2;

            br = 0;
        }
    }

    cout << br << endl;
    return 0;

}
/**
7
14 231 23 41 6 132 123
*/
