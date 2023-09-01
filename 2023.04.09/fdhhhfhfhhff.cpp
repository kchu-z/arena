#include <bits/stdc++.h>
using namespace std;

string dp[27];
bool check[27];

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

string f(long long n) {
    if (n == 1) return "1";
    if (check[n]) return dp[n];
    check[n] = 1;

    return dp[n] = mult(f(n - 1), n * (2 * n - 1));
}

int main() {

    int n;
    cin >> n;

    string s = f(n);
    reverse(s.begin(), s.end());

    cout << s << endl;
    return 0;

}
