#include <bits/stdc++.h>
using namespace std;

string mul(string& s, long long n) {
    string str;
    long long pr = 0;

    for (int i = 0; i < s.size() || pr; i++) {
        long long sum = pr;
        if (i < s.size()) sum += (int) (s[i] - '0') * n;

        pr = sum / 10;
        str.push_back(sum % 10 + '0');
    }

    reverse(str.begin(), str.end());
    return str;
}

int main() {

    string s;
    long long n;
    cin >> s >> n;

    reverse(s.begin(), s.end());
    cout << mul(s, n);

    return 0;

}
