#include <bits/stdc++.h>
using namespace std;

string add1(string& s) {
    string ans;

    int pr = 1;

    for (int i = 0; i < s.size() || pr; i++) {
        int sum = pr;
        if (i < s.size()) sum += s[i] - '0';

        pr = sum / 10;
        ans.push_back(sum % 10);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int N = s.size();

    string first = s.substr(0, (N - 1) / 2 + 1);

    string first_reverse = first;
    reverse(first_reverse.begin(), first_reverse.end());

    string second_reverse = s.substr(N / 2, -1);
    string second = second_reverse;
    reverse(second.begin(), second.end());

    cout << first << ' ' << second << endl;

    if (first == second) {
        cout << s;
        return 0;
    } else if (first_reverse >= second || first >= second) {
        if (N % 2) {
            string ans = first;
            ans.pop_back();
            ans += first_reverse;

            cout << ans << endl;
        } else {
            string ans = first;
            ans += first_reverse;

            cout << ans << endl;
        }
    } else {
        string added_1 = add1(first);

        if (added_1.size() == first.size()) {

        }
    }

    return 0;
}

