#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    long long n = 0, sum = 0;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) continue;
        if (s[i] != '-') s[i] = '_';
        else if (i + 1 == s.size()) s[i] = '_';
        else if (!isdigit(s[i + 1])) s[i] = '_';
    }

    //cout << s << ' ';

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            sum += n;
            i++;
            n = -(s[i] - '0');
        } else if (isdigit(s[i])) {
            n = n * 10 + s[i] - '0';
        } else {
            sum += n;
            n = 0;
        }
    }

    cout << sum + n << endl;

    return 0;

}
