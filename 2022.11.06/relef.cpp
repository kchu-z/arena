#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, mn = 0;
    char s;
    cin >> n;
    vector <int> v(n);

    for (int i = 1; i < n; i++) {
        cin >> s;
        if (s == '<') v[i] = v[i - 1] + 1;
        else v[i] = v[i - 1] - 1;
        mn = min(mn, v[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] - mn << ' ';
    }

    return 0;

}
