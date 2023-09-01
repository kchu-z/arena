#include <bits/stdc++.h>
using namespace std;

string sub(string& a, string& b) {
    string ans;
    long long pr = 0;

    for (int i = 0; i < a.size(); i++) {
        long long sum = -pr;
        sum += a[i] - '0';
        sum -= b[i] - '0';

        if (sum < 0) {
            sum += 10;
            pr = 1;
        } else pr = 0;

        ans.push_back(sum + '0');
    }

    while (ans.size() && ans.back() == '0') ans.pop_back();
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    string a = s;
    sort(a.begin(), a.end());
    string b = a;
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != '0') {
            char cs = a[i];
            a[0] = cs;
            a[i] = '0';
            break;
        }
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans = sub(b, a);
    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;

}
