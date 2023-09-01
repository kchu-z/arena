#include <bits/stdc++.h>
using namespace std;

string sub(string& a, string& b) {
    string sol;
    long long pr = 0;

    for (int i = 0; i < max(a.size(), b.size()) || pr; i++) {
        long long ans = pr;
        if (i < a.size()) ans += a[i] - '0';
        if (i < b.size()) ans += b[i] - '0';

        pr = ans / 10;

        sol.push_back(ans % 10 + '0');
    }

    return sol;
}

int main() {

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << sub(a, b);
}
