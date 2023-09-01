#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    string n;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    bool f = false;

    for (int i = 0; i < max(a.size(), b.size()) || f; i++) {
        int sum = f;

        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        n.push_back(sum % 10 + '0');
        f = sum / 10;
    }

    reverse(n.begin(), n.end());
    return n;
}

string pow10(string a, int n) {
    for (int i = 0; i < n; i++) a.push_back('0');
    return a;
}

string mul(string a, string b) {
    int pow10_ = 0;

    string res = "0";

    for (int i = b.size() - 1; i >= 0; i--) {
        string curr = "0";
        int mul = b[i] - '0';

        for (int i = 0; i < mul; i++) {
            curr = add(curr, a);
        }

        res = add(res, pow10(curr, pow10_));

        pow10_++;
    }

    return res;
}

int main() {

    int n, sum = 0;
    cin >> n;

    string res = "1";

    for (int i = 2; i <= n; i++) {
        res = mul(res, to_string(i));
    }

    for (char i : res) sum += i - '0';

    cout << sum;

    return 0;

}
