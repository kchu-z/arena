#include <bits/stdc++.h>
using namespace std;

string div(string s, long long d) {
    string ans;
    long long pr = 0;

    for (int i = 0; i < s.size(); i++) {
        long long sum = (pr * 10 + (s[i] - '0'));
        pr = sum % d;

        ans.push_back(sum / d + '0');
    }

    reverse(ans.begin(), ans.end());
    while (ans.size() && ans.back() == '0') ans.pop_back();

    reverse(ans.begin(), ans.end());

    if (ans.empty()) return "0";
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    long long d, br = 0;
    cin >> s >> d;

    cout <div(s, d);
    return 0;

}

