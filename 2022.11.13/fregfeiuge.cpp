#include <bits/stdc++.h>
using namespace std;

string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string from10(long long n, int base) {
    if (n == 0) return 0;
    string s;

    while (n) {
        s.push_back(ch[n % base]);
        n /= base;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main() {

    long long n;
    cin >> n;
    vector <int> v;

    for (int i = 2; i <= 36; i++) {
        string s = from10(n, i);
        string s1 = s;
        reverse(s1.begin(), s1.end());

        if (s == s1) v.push_back(i);
    }

    if (v.size() == 0) cout << "none";
    else if (v.size() == 1) cout << "unique\n" << v[0] << endl;
    else {
        cout << "multiple" << endl;
        for (int i : v) cout << i << ' ';
    }

    return 0;

}
