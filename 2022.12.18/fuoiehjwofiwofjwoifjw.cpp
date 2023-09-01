#include <bits/stdc++.h>
using namespace std;

string add(string& a, string& b) {
    string ans;
    bool pr = 0;

    for (int i = 0; i < max(a.size(), b.size()) || pr; i++) {
        int sum = pr;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        pr = sum / 10;
        ans.push_back(sum % 10);
    }

    return ans;
}

string mult(string& a, string& b) {
    vector <int> ans(a.size() + b.size());
    string res;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            ans[i + j] = (a[i] - '0') * (b[j] - '0');
        }
    }

    for (int i = 0; i < a.size() + b.size(); i++) {
        if (i + 1 < a.size() + b.size()) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }

        res.push_back(ans[i] + '0');
    }

    while (res.size() > 1 && res.back() == '0') res.pop_back();
    return res;
}

void subtract_1(string& s) {
    for (int i = 0; i < s.size(); i++) {
        int sum = s[i] - '0' - 1;

        if (sum < 0) {
            sum += 10;
            s[i] = sum + '0';
        } else {
            s[i] = sum + '0';
            break;
        }
    }


    while (s.size() > 1 && s.back() == '0') s.pop_back();
}

string combinations(string maxsize, int currentsize) {
    string ans = "1";

    for (int i = 0; i < currentsize; i++) {
        ans = mult(ans, maxsize);
        subtract_1(maxsize);
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long br = 0;
    string s, m;
    cin >> s >> m;

    string res = "0";

    sort(s.begin(), s.end());

    for (char i : m) {
        bool f = 1;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == i) s.erase(j);
            f = true;
            break;
        }

        if (!f) {
            cout << 0;
            return 0;
        }
    }

    for (int i = 0; i <= s.size(); i++) {
        string tostr = to_string(i + 1);
        string comb = combinations(to_string(s.size()), i);
        string mlt = mult(tostr, comb);
        res = add(res, mlt);
    }

    cout << res << endl;
    return 0;

}
