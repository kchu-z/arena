#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    bool pr = false;
    string n;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        char A = '0';
        char B = '0';

        if (i < a.size()) A = a[i];
        if (i < b.size()) B = b[i];

        int sum = A + B + (int) pr - 2 * '0';
        if (sum > 9) {pr = true;sum-=10;}
        else pr = false;

        n.push_back(sum + '0');
    }

    if (pr) n.push_back('1');
    reverse(n.begin(), n.end());

    return n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    cout << add(a, b);

    return 0;

}
