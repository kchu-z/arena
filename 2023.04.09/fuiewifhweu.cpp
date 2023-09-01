#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k, f, a, b, m, current;
    cin >> n >> k >> f >> a >> b >> m;

    current = f;

    deque <pair <long long, int> > q = {{0, 0}};
    //cout << endl;

    for (int i = 1; i <= n + 1; i++) {
        if (q.size() && q.front().second < i - k) q.pop_front();

        long long dp = current + q.front().first;
        if (i == n + 1) dp -= current;
        //cout << dp[i] << ' ';

        while (q.size() && q.back().first >= dp) q.pop_back();
        q.push_back({dp, i});
        current = (current * a + b) % m;
    }

    //cout << endl;

    cout << q.back().first << endl;
    return 0;

}
