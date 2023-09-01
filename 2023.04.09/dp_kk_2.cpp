#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    unordered_map <char, priority_queue <int>> dp1;
    priority_queue <int> dp;
    for (int n = 0; n < s.size(); n++) {
        int temp = (dp.empty() ? 0 : dp.top()) + 1;
        if (!dp1[s[n]].empty()) dp.push(dp1[s[n]].top() + 1);
        dp1[s[n]].push(temp);
    }
    cout << (int) s.size() - (dp.empty() ? 0 : dp.top()) << endl;
    return 0;
}
