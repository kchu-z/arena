#include <bits/stdc++.h>
using namespace std;

string div(string number, long long divisor) {
    string ans = "";

    if (number == "0") return "0";

    long long idx = 0;
    long long temp = (long long)(number[idx] - '0');

    while (temp < divisor) {
        temp = temp * 10 + (int)(number[idx + 1] - '0');
        idx++;
    }

    idx++;

    while (number.size() > idx) {
        ans.push_back(temp / divisor + '0');
        temp = (temp % divisor) * 10 + (int)(number[idx] - '0');
        idx++;
    }

    ans.push_back(temp / divisor + '0');

    if (ans.size() == 0) return "0";
    return ans;
}

string sub(string a, string b) {
    string n;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    bool pr = false;

    for (int i = 0; i < max(a.size(), b.size()); i++) {
        char A = '0', B = '0';

        if (i < a.size()) A = a[i];
        if (i < b.size()) B = b[i];

        int res = A - B - (int) pr;

        if (res < 0) {
            pr = true;
            res += 10;
        } else {
            pr = false;
        }

        n.push_back(res + '0');
    }

    while (n.back() == '0') n.pop_back();
    reverse(n.begin(), n.end());

    if (n.size() == 0) n.push_back('0');

    return n;
}

int main() {

    long long a;
    string b, c;
    cin >> a >> b >> c;

    cout << div(sub(b, c), a);

    return 0;

}

