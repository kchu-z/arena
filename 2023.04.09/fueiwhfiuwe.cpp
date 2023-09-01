#include <bits/stdc++.h>
using namespace std;

string dp[1001][1001];

string add(string& a, string& b) {
    string ans;
    long long pr = 0;

    for (int i = 0; i < max(a.size(), b.size()) || pr; i++) {
        long long sum = pr;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return ans;
}

string multiply(string& a, long long b) {
    string ans;
    long long pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        long long sum = pr;
        if (i < a.size()) sum += b * (a[i] - '0');

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return a = ans;
}

string divide(string& a, long long b) {
    string ans;
    long long pr = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        long long sum = pr * 10;
        if (i < a.size()) sum += a[i] - '0';

        pr = sum % b;
        sum /= b;

        ans.push_back(sum + '0');
    }

    reverse(ans.begin(), ans.end());
    while (ans.size() && ans.back() == '0') ans.pop_back();
    //reverse(ans.begin(), ans.end());

    return a = ans;
}

string c(long long n, long long k) {
    string ans = "1";

    for (long long i = 1; i <= k; i++) {
        multiply(ans, n - k + i);
        divide(ans, i);
    }

    return ans;
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k, br = 0;
    cin >> n >> k;

    string ans = c(n, k);
    //cout << ans << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == '0') br++;
    }



    cout << br << endl;
    return 0;

}
