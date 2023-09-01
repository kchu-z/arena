#include <bits/stdc++.h>
using namespace std;

string mult(string& a, string& b) {
    vector <int> ans(a.size() + b.size(), 0);
    string res;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            ans[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }

    for (int i = 0; i < a.size() + b.size() - 1; i++) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }

    for (int i = 0; i < a.size() + b.size(); i++) res.push_back(ans[i] + '0');
    while (res.size() > 1 && res.back() == '0') res.pop_back();

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;


    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    bool isNegative = (a.back() == '-') != (b.back() == '-');
    if (a.back() == '-') a.pop_back();
    if (b.back() == '-') b.pop_back();

    string ans = mult(a, b);
    if (isNegative && ans != "0") ans.push_back('-');
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;

}
