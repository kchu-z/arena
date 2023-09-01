#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    string ans;
    bool pr = 0;

    for (int i = 0; i < max(a.size(), b.size()) || pr; i++) {
        int sum = pr;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return ans;
}


string sub(string a, string b) {
    string ans;
    bool pr = 0;

    for (int i = 0; i < a.size(); i++) {
        int sum = (a[i] - '0') - pr;
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

string mult(string a, long long b) {
    string ans;
    long long pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        long long sum = pr;
        if (i < a.size()) sum += b * (a[i] - '0');

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return ans;
}

pair <string, long long> div(string a, long long b) {
    string ans;
    long long pr = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        long long sum = pr * 10 + (a[i] - '0');
        pr = sum % b;

        ans.push_back(sum / b + '0');
    }

    reverse(ans.begin(), ans.end());

    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
    return {ans, pr};
}

int main() {

    long long tenth_power, num;
    cin >> tenth_power >> num;

    string ans, res;

    while (tenth_power > 1) {
        ans.push_back('0');
        tenth_power--;
    }

    ans.push_back('1');

    long long mod = div(ans, num).second;
    //cout << mod << endl;

    string _mod = to_string(mod), _num = to_string(num);
    reverse(_mod.begin(), _mod.end());
    reverse(_num.begin(), _num.end());

    if (mod == 0) res = ans;
    else res = add(sub(ans, _mod), _num);

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;

}
