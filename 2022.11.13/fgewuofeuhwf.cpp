#include <bits/stdc++.h>
using namespace std;

unordered_map <long long, long long> m;

vector <pair <long long, long long> > d(long long n) {
    vector <pair <long long, long long>> v;

    for (long long i = 2; i * i <= n; i++) {
        int br = 0;

        while (n % i == 0) {
            br++;
            n /= i;
        }

        if (i != 0) v.push_back({i, br});
    }

    if (n != 1) v.push_back({n, 1});
    return v;
}

void add_to_product(vector <pair <long long, long long> >& v) {
    for (auto& i : v) m[i.first] += i.second;
}

void remove_from_product(vector <pair <long long, long long> >& v) {
    for (auto& i : v) m[i.first] -= i.second;
}

string mul(string s, long long n) {
    if (n == 0) return "0";
    string str;

    long long pr = 0;

    for (int i = 0; i < s.size() || pr; i++) {
        long long sum = pr;
        if (i < s.size()) sum += n * (s[i] - '0');

        pr = sum / 10;

        str.push_back(sum % 10 + '0');
    }

    return str;
}

long long pow(long long n, long long p) {
    if (p == 0) return 1;
    return n * pow(n, p - 1);
}

int main() {

    long long n, k;
    cin >> n >> k;

    string p = "1";

    for (long long i = n; i > n - k; i--) {
        auto s = d(i);
        add_to_product(s);
    }

    for (long long i = 2; i <= k; i++) {
        auto s = d(i);
        remove_from_product(s);
    }

    for (auto& s : m) {
        //cout << s.first << ' ' << s.second << endl;

        for (int i = 0; i < s.second / 4; i++) {
            p = mul(p, pow(s.first, 4));
        }
        p = mul(p, pow(s.first, s.second % 4));
    }

    reverse(p.begin(), p.end());
    cout << p << endl;

    return 0;

}
