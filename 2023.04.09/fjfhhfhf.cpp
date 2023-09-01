#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    long long n = s.size(), boys = 0, girls = 0;
    long long claps = 0, words = 0;

    for (int i = 0; i < n; i++) {
        char sign = s[i];

        if (sign == '-') {
            claps += boys;
            words += 2 * girls;
            boys++;
        } else {
            //cout << boys + girls << endl;
            if (boys + girls) words += 1 + (boys + girls);
            girls++;
        }

        //cout << claps << ' ' << words << endl;
    }

    cout << claps << ' ' << words << endl;
    return 0;

}

