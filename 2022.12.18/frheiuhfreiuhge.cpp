#include <bits/stdc++.h>
using namespace std;

string add(string& a, string& b) {
    string ans;
    bool pr;

    for (int i = 0; i < max(a.size(), b.size()) || pr; i++) {
        int sum = pr;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        pr = sum / 10;
        ans.push_back(sum % 10 + '0');
    }

    return ans;
}

pair <string, string> fib(int n) {
    if (n == 1) return {"1", "1"};
    if (n == 2) return {"2", "1"};
    pair <string, string> f = fib(n - 1);
    string a = add(f.first, f.second);

    return {a, f.first};
}

int main() {

    int n;
    cin >> n;

    pair <string, string> f = fib(n);
    f.second = add(f.first, f.second);

    reverse(f.first.begin(), f.first.end());
    reverse(f.second.begin(), f.second.end());

    cout << f.first << ' ' << f.second << endl;
    return 0;

}
