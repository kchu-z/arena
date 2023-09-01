#include <bits/stdc++.h>
using namespace std;

string mult(string& a, long long b) {
    if (a == "0" || b == 0) return "0";
    string ans;
    long long pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        long long sum = pr;
        if (i < a.size()) sum += (a[i] - '0') * b;

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a;
    long long b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    cout << mult(a, b);
    return 0;

}
