#include <bits/stdc++.h>
using namespace std;

string mult(string& a, long long b) {
    if (b == 0) return "0";

    string ans;
    long long pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        long long sum = pr;
        if (i < a.size()) sum += (int) (a[i] - '0') * b;

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return ans;
}

int main() {

    string s;
    long long n;
    cin >> s >> n;

    reverse(s.begin(), s.end());
    s = mult(s, n);
    reverse(s.begin(), s.end());

    cout << s << endl;
    return 0;

}
