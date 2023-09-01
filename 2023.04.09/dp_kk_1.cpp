#include <bits/stdc++.h>
using namespace std;

string s;
unordered_map <char, int> convert;

vector <priority_queue <pair <int, string>>> dp_1(26);
priority_queue <pair <int, string>> dp;

void f(int n) {
    if (n < 0) return;
    f(n - 1);

    string temp = (dp.empty() ? "" : dp.top().second) + to_string(s[n]), var;
    if (!dp_1[s[n] - 'a'].empty()) var = dp_1[s[n] - 'a'].top().second + to_string(s[n]);

    dp_1[s[n] - 'a'].push({temp.size(), temp});
    if (!var.empty()) dp.push({var.size(), var});
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 26; i++) convert[i + 'a'] = i;

    cin >> s;
    f(s.size() - 1);

    cout << s.size() - dp.top().second.size() << endl;

    return 0;

}
