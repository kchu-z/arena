#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    /*bool f1 = false, f2 = false;
    int i1 = 0, i2 = 0, sum = 0;



    if (s[0] == '-') {

        if (s[1] == '1') {
            f1 = true;
            i1 = 1;
        }

        for (int j = 1; j < s.size(); j++) {

            sum += s[j] - '0';
        }

        for (int j = 1; j < s.size(); j++) {
            char i = s[j];


        }
    } else {
        for (char& i : s) {
            sum += i - '0';
        }

        for (char& i : s) {
            if (i != '9') {
                if (!f1 && i != s.back()) {
                    f1 = true;
                    i = '9';

                    sum += 9 - i + '0';

                    if (s.back() % 2 != 0) {
                        sum -= s.back() - '0';
                        if (sum % 3 == 0) s.back() = '6';
                        else if (sum % 3 == 1) s.back() = '8';
                        else if (sum % 3 == 2) s.back() = '4';

                        cout << s << endl;
                        return 0;
                    }
                } else if (!f2 && i != s.back()) {

                }
            }
        }
    }*/

    cout << s;

    return 0;

}
