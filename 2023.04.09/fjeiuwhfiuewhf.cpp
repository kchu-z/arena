#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,br =0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s = to_string(i), s1 = s;
        reverse(s1.begin(), s1.end());
        if (s1 == s) br++;
    }

    cout << br << endl;
    return 0;

}
