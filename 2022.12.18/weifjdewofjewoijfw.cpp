#include <bits/stdc++.h>
using namespace std;

string mult2(string& s) {
    string ans;
    int pr = 0;

    for (int i = 0; i < s.size() || pr; i++) {
        int sum = pr;
        if (i < s.size()) sum += (s[i] - '0') * 2;

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return ans;
}

string add(string& a, string& b) {
    string ans;
    int pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        int sum = pr;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return ans;
}

string sub(string& a, string& b) {
    string ans;
    int pr = 0;

    for (int i = 0; i < a.size(); i++) {
        int sum = (a[i] - '0') - pr;
        if (i < b.size()) sum -= b[i] - '0';

        if (sum < 0) {
            pr = 1;
            sum += 10;
        } else pr = 0;

        ans.push_back(sum + '0');
    }

    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    return ans;
}

int main() {

    int n;
    string m, ans = "1";

    cin >> n >> m;
    reverse(m.begin(), m.end());

    for (int i = 0; i < n; i++) ans = mult2(ans);

    if (m.back() == '-') {
        m.pop_back();
        ans = add(ans, m);
    } else ans = sub(ans, m);
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;

}
