#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool simple(int n) {
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }

    return true;
}

string tostring(int n) {
    string v;

    while (n) {
        v.push_back(n % 10 + '0');
        n /= 10;
    }

    reverse(v.begin(), v.end());
    return v;
}

int toint(string& v) {
    int n = 0;

    for (int i = (int) v.size() - 1; i >= 0; i--) {
        n = n * 10 + i - '0';
    }

    return n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        string v = tostring(i);
        bool f = true;

        for (int j = 1; j <= v.size(); j++) {
            string s = v.substr(0, j);
            if (!simple(toint(s))) {
                f = false;
                break;
            }
        }

        if (f) cout << i << endl;
    }

    return 0;

}
