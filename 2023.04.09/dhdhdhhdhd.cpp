#include <bits/stdc++.h>
using namespace std;

long long c[70][70];

bool visited[27];
string dp[27];

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

    if (visited[n]) return dp[n];
    visited[n] = 1;

    return dp[n] = mult(f(n - 1), n * (2 * n - 1));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 69; i++) {
        c[i][0] = 1;

        for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    long long n;
    cin >> n;

    string s = f(n);
    reverse(s.begin(), s.end());

    cout << s << endl;
    return 0;

}
