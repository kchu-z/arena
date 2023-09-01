#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector <int> v, res;
long long n, p;

vector <int> from_10(long long num) {
    vector <int> ans;

    while (num) {
        ans.push_back(n % p);
        num /= p;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

long long to_10(vector <int> v) {
    long long ans = 0;

    for (int i : v) {
        ans = ans * p + i;
    }

    return ans;
}

void solve(int start) {
    if (start == res.size()) {
        long long num = to_10(res);

        if (num <= n) {
            if (num != 0) cout << num << endl;
        } else exit(0);
    } else {
        res[start] = 0;
        solve(start + 1);
        res[start] = 1;
        solve(start + 1);
    }
}

int main() {

    cin >> n >> p;
    v = from_10(n);

    //for (int i : v) cout << i << ' ';
    //cout << endl;

    for (int i = 0; i < v.size(); i++) {
        res.push_back(0);
        v[i] = min(v[i], 1);
    }

    solve(0);

    return 0;

}
