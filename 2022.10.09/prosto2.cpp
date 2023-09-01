#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool simple(int n) {
    if (n < 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }

    return true;
}

string tostring(int n) {
    string v;

    while (n) {
        v.push_back((n % 10) + '0');
        n /= 10;
    }

    reverse(v.begin(), v.end());
    return v;
}

int main() {

    int a, b;
    cin >> a >> b;
    bool f, m = false;

    if (a == 1) {
        cout << 1 << endl;
        a++;
    }

    if (a == 2) {
        cout << 2 << endl;
        a++;
    } else if (a % 2 == 0) a++;

    for (int i = a; i <= b; i += 2) {
        string v = tostring(i);
        int s = 0;
        f = true;

        for (auto& c : v) {
            s = s * 10 + (c - '0');
            if (!simple(s)) {
                f = false;
                break;
            }
        }

        if (f) {
            cout << i << endl;
            m = true;
        }
    }

    if (!m) cout << "NO";

    return 0;

}
