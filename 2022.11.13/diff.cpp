#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    string n;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    bool f = false;

    for (int i = 0; i < max(a.size(), b.size()) || f i++) {
        char A = '0';
        char B = '0';

        if (i < a.size()) A = a[i];
        if (i < b.size()) B = b[i];

        int sum = (A - '0') - (B - '0') - f;

        if (sum < 0) {
            sum += 10;
            f = true;
        } else f = false;

        n.push_back(sum + '0');
    }

    //while (n.back() == '0') n.pop_back();

    if (f) n.push_back('-');

    reverse(n.begin(), n.end());
    return n;
}

int main() {

    string a, b;
    cin >> a >> b;

    cout << add(a, b);

    return 0;

}
