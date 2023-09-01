#include <bits/stdc++.h>
using namespace std;

string mul(string a, int x) {
    reverse(a.begin(), a.end());
    string s;

    int pr = 0;

    for (char& i : a) {
        int m = (i - '0') * x + pr;
        pr = m / 10;
        m %= 10;

        s.push_back(m + '0');
    }

    reverse(s.begin(), s.end());
    if (pr != 0) s = to_string(pr) + s;

    return s;
}

int main() {

    int k;
    //cin >> k;
    string a; cin >> a; cout << mul(a, k);
    string s;

    long long i = 1;

    while (s.size() < k) {
        s += to_string(i * i * i);
        ///cout << i * i * i << endl;
        i++;
    }

    cout << s[k - 1];

    return 0;

}
