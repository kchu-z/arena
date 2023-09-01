#include <bits/stdc++.h>
using namespace std;

string add(string& a, string& b) {
    string ans;
    bool pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        int sum = pr;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        if (sum >= 10) {
            sum -= 10;
            pr = true;
        } else pr = false;

        ans.push_back(sum + '0');
    }

    return ans;
}

string sub(string& a, string& b) {
    if (b.back() == '-') {
        b.pop_back();
        return add(a, b);
    }

    string ans; /// a > b > 0
    bool pr = 0;

    for (int i = 0; i < a.size(); i++) {
        int sum = a[i] - '0' - pr;
        if (i < b.size()) sum -= b[i] - '0';

        if (sum < 0) {
            sum += 10;
            pr = true;
        } else pr = false;

        ans.push_back(sum + '0');
    }

    while (ans.back() == '0' && ans.size() > 1) ans.pop_back();
    return ans;
}

string mul(string& s, long long n) {
    if (n == 0 || s == "0") return "0";
    if (n == 1) return s;

    string ans;
    long long pr = 0;

    for (int i = 0; i < s.size() || pr; i++) {
        long long sum = pr;
        if (i < s.size()) sum += (s[i] - '0') * n;

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return ans;
}

string long_division(string& s, long long n) {
    string ans;
    long long pr = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        long long quotient = pr * 10 + (s[i] - '0');
        pr = quotient % n;
        quotient /= n;

        if (quotient || !ans.empty()) ans.push_back(quotient + '0');
    }

    return ans;
}

string s = "00000000000000000000";
int br = 0;

void solve(int pos) {
    if (pos == 20) {
        string p = "0";

        for (int i = 0; i < 20; i++) {
            p = mul(p, 2);
            if (s[i] == '1') p.front()++;
        }

        reverse(p.begin(), p.end());
        if (p == "0") return;
        long long d = stoll(p);

        string num = s;
        reverse(num.begin(), num.end());

        string quotient = long_division(num, d);
        reverse(quotient.begin(), quotient.end());

        if (num == mul(quotient, d)) {
            cout << s << endl;
            br++;
        }

        //cout << p << endl;
    } else {
        s[pos] = '0';
        solve(pos + 1);
        s[pos] = '1';
        solve(pos + 1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve(0);
    cout << br << endl;
}
