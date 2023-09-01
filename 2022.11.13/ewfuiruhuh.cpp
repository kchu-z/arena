#include <bits/stdc++.h>
using namespace std;

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

int main() {

    string a;
    long long b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    string p = mul(a, b);
    reverse(p.begin(), p.end());
    cout << p;

    return 0;

}
