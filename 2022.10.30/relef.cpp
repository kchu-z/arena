#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, br = 1;
    char s;
    cin >> n;
    cout << 1;

    for (int i = 1; i < n; i++) {
        cin >> s;
        br += (s == '>') ? -1 : 1;
        cout << ' ' << br;
    }

    return 0;

}
