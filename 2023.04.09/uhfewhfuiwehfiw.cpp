#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
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

string sub(string a, string b) {
    string sol;
    long long pr = 0;

    for (int i = 0; i < max(a.size(), b.size()); i++) {
        long long ans = -pr;
        if (i < a.size()) ans += a[i] - '0';
        if (i < b.size()) ans -= b[i] - '0';

        if (ans < 0) {
            pr = 1;
            ans += 10;
        } else pr = 0;

        sol.push_back(ans + '0');
    }

    while (sol.size() && sol.back() == '0') sol.pop_back();

    return sol;
}

string get_number(long long digits) {
    string s;

    for (int i = 0; i < digits - 1; i++) s.push_back('0');
    s.push_back('9');

    return s;
}

string get_lower_number(long long digits) {
    string s;

    for (int i = 0; i < digits; i++) s.push_back('9');
    return s;
}

string get_upper_number(long long digits) {
    string s;

    for (int i = 0; i < digits - 1; i++) s.push_back('0');
    s.push_back('1');

    return s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    long long lower_digits = a.size(), upper_digits = b.size();
    if (lower_digits % 2 != 0) lower_digits++;
    if (upper_digits % 2 != 0) upper_digits--;

    if (lower_digits > upper_digits) {
        cout << 0 << endl;
        return 0;
    }

    lower_digits /= 2;
    upper_digits /= 2;

    cout << lower_digits << ' ' << upper_digits << endl;

        if (a.size() == b.size()) {
            string lower2 = a.substr(0, lower_digits);
            string lower = a.substr(lower_digits, lower_digits);
            string upper2 = b.substr(0, upper_digits);
            string upper = b.substr(upper_digits, upper_digits);

            string current = sub(sub(upper, lower), "1");
            reverse(lower.begin(), lower.end());
            reverse(lower2.begin(), lower2.end());
            reverse(upper.begin(), upper.end());
            reverse(upper2.begin(), upper2.end());

            if (lower >= lower2) current = add(current, "1");
            if (upper <= upper2) current = add(current, "1");

            reverse(current.begin(), current.end());
            cout << current << endl;
        } else if (a.size() == 2 * lower_digits) {
            string lower2 = a.substr(0, lower_digits);
            string lower = a.substr(lower_digits, lower_digits);

            string current = sub(get_lower_number(lower_digits), lower);
            reverse(lower.begin(), lower.end());
            reverse(lower2.begin(), lower2.end());

            if (lower >= lower2) current = add(current, "1");

            for (int i = lower_digits + 1; i <= upper_digits; i++) {
                current = add(current, get_number(i));
            }

            reverse(current.begin(), current.end());
            cout << current << endl;
        } else if (b.size() == 2 * upper_digits) {

        } else {

        }

    return 0;

}
