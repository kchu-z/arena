#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    long long n = 0, sum = 0;
    bool neg = false;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            //if (s[i] == '0') {
            //    if (!isdigit(s[i - 1])) s[i] = '_';
            //}
        } else if (s[i] != '-') s[i] = '_';
        else if (i + 1 == s.size()) s[i] = '_';
        else if (!isdigit(s[i + 1])) s[i] = '_';
    }

    cout << s << endl;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            if (neg) sum -= n;
            else sum += n;
            n = 0;

            neg = true;
        } else if (isdigit(s[i])) {
            n = n * 10 + s[i] - '0';
        } else {
            if (neg) sum -= n;
            else sum += n;
            n = 0;

            neg = false;
        }
    }

    if (neg) sum -= n;
    else sum += n;

    cout << sum << endl;

    return 0;

}
