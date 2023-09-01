#include <bits/stdc++.h>
using namespace std;

long long n, k, m, pos, num;
vector <long long> a, c;
string str;

long long mod(long long x) {
    if (x >= 0) return x % m;
    return x % m + m;
}

void get_next() {
    long long s = 0;

    for (int i = 0; i < n; i++) s += a[i] * c[n - i - 1];
    s = mod(s);

    a.erase(a.begin());
    a.push_back(s);
}

int main() {

    cin >> n >> k >> m;
    k--;

    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);

        str.push_back((char) a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        c.push_back(num);
    }

    for (long long i = n; 1; i++) {
        get_next();

        //cout << a.back() << ' ';
        str.push_back(mod(a.back()));

        string arr = str.substr(str.size() - n, n);
        pos = str.find(arr);

        if (pos < str.size() - n) {
            char s;
            //cout << '\n';
            //for (char j : str) cout << (int) j << ' ';
            //cout << '\n';

            if (k <= i) s = str[k];
            else s = str[pos + (k - pos) % (str.size() - n - pos)];

            cout << (int) s << '\n';
            return 0;
        }
    }

    return 0;

}
