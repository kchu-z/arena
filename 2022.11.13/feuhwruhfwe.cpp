#include <bits/stdc++.h>
using namespace std;

string add(string& a, string& b) {
    string ans;
    bool pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        int sum = pr;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        if (sum >= 10) {
            sum -= 10;
            pr = true;
        } else pr = false;

        ans.push_back(sum + '0');
    }

    return ans;
}

int main() {

    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());

    cout << add(a, b);

}
