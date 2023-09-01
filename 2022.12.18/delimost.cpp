#include <bits/stdc++.h>
using namespace std;

string sub(string& a, string& b) {
    string ans;
    bool pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        int sum = - pr;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum -= b[i] - '0';

        if (sum < 0) {
            sum += 10;
            pr = 1;
        } else pr = 0;

        ans.push_back(sum + '0');
    }

    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    return ans;
}

pair <string, long long> div(string& a, long long b) {
    string ans;
    long long pr = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        long long sum = pr * 10 + a[i] - '0';
        pr = sum % b;

        ans.push_back(sum / b + '0');
    }

    reverse(ans.begin(), ans.end());

    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    return {ans, pr};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    for (long long i = 2; i <= 2001; i++) {
        pair <string, long long> x = div(s, i);

        if (x.second == 0) {
            reverse(x.first.begin(), x.first.end());
            cout << i << ' ' << x.first << '\n';
        }
    }

    return 0;

}

