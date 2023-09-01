#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string add(string& a, string& b) {
    string n;
    bool f = false;

    for (int i = 0; i < max(a.size(), b.size()) || f; i++) {
        int sum = f;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        if (sum < 10) f = false;
        else {
            f = true;
            sum -= 10;
        }

        n.push_back(sum + '0');
    }

    return n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;
    unordered_map <string, int> m;
    vector <string> v(n);

    string sum = "0";

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());

        m[v[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (m[v[i]] == 1) {
            //cout << v[i] << ' ' << sum << endl;
            sum = add(sum, v[i]);
        }
    }

    reverse(sum.begin(), sum.end());

    cout << sum << endl;

    return 0;
}
/// 7 1 4 22 99 40 10 4
