#include <bits/stdc++.h>
using namespace std;

string multiply(string& a, long long b) {
    string ans;
    long long pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        long long sum = pr;
        if (i < a.size()) sum += b * (a[i] - '0');

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return a = ans;
}


string divide(string& a, long long b) {
    string ans;
    long long pr = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        long long sum = pr * 10;
        if (i < a.size()) sum += a[i] - '0';

        pr = sum % b;
        sum /= b;

        ans.push_back(sum + '0');
    }

    reverse(ans.begin(), ans.end());
    while (ans.size() && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());

    return a = ans;
}

int main() {

    string a;
    long long b;
    cin >> a >> b;

    reverse(a.begin(), a.end());

    cout << divide(a, b) << endl;

}
