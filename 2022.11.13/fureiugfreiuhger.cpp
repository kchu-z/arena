#include <bits/stdc++.h>
using namespace std;

string long_division(string& a, long long b) {
    string c;
    long long pr = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        pr = pr * 10 + a[i] - '0';
        c.push_back(pr / b + '0');
        pr %= b;
    }

    reverse(c.begin(), c.end());
    while (c.back() == '0' && c.size() > 1) c.pop_back();
    reverse(c.begin(), c.end());
    return c;
}

int main() {
    while(1){
    string a;
    long long b;
    cin >> a >> b;
    reverse(a.begin(), a.end());

    cout << long_division(a, b) << endl;
    }
    return 0;

}
