#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char s;
    int n, k, br = 0, num;
    cin >> n >> k;

    vector <char> v(n, '?');

    for (int i = 0; i < k; i++) {
        cin >> num >> s;
        br = (br + num) % n;

        if (v[br] == '?' || v[br] == s) v[br] = s;
        else {
            cout << '!';
            return 0;
        }
    }

    for (int i = br; i >= 0; i--) cout << v[i];
    for (int i = n - 1; i > br; i--) cout << v[i];
    cout << endl;

    return 0;

}
