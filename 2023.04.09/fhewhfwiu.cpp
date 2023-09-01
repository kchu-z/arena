#include <bits/stdc++.h>
using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int sum_of_digits = 0;
    for (char c : s) sum_of_digits += c - '0';

    sum_of_digits = 3 - (sum_of_digits % 3);

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (s[i] + sum_of_digits <= '9') {
            s[i] = s[i] + sum_of_digits;

            while (s[i] + 3 <= '9') s[i] += 3;

            cout << s << endl;
            return 0;
        }
    }

    s[s.size() - 1] -= (sum_of_digits == 3) ? 3 : (3 - sum_of_digits);
    cout << s << endl;

    return 0;

}
