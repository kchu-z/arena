#include <bits/stdc++.h>
using namespace std;

int d;

bool check(int a, int b) {
    string A = to_string(a);
    string B = to_string(b);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    return A == B;
}

int mx = 0;
vector <pair <int,int>> ans;

void ex(int a, int b) {
    int n = abs(a - b);
    int br = 0;

    while (n) {
        if (n % 10 == d) br++;

        n /= 10;
    }

    if (mx == br) {
        ans.push_back({a, b});
    } else if (mx > br) {
        mx = br;
        ans.clear();
        ans.push_back({a, b});
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> d;

    for (int i = 100000; i <= 999999; i++) {
        string s = to_string(i);
        sort(s.begin(), s.end());

        do {
            if (s[0] == '0') continue;

            ex(i, stoi(s));
        } while (next_permutation(s.begin(), s.end()));

    }

    cout << mx << endl;

    sort(ans.begin(), ans.end());
    cout << ans[0].first << ' ' << ans[0].second << endl;

    return 0;

}
